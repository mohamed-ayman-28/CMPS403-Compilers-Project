%{
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "symbol_table.h"
#include "ir.h"

void yyerror(const char *s);
int yylex(void);
extern FILE* yyin;
extern scope_no;
extern yylineno;

SymbolTable* symbol_table = create_symbol_table();
Parameter* curr_function_parameter_list = NULL;
Parameter* curr_function_parameter_list_ptr = NULL;
Parameter* curr_function_instructions_list = NULL;
int inside_a_function_declaration_body = 0;

ValueType string_to_value_type(const char* type_str) {
    if (strcmp(type_str, "int") == 0) return INT_VALUE;
    else if (strcmp(type_str, "float") == 0) return FLOAT_VALUE;
    else if (strcmp(type_str, "char") == 0) return CHAR_VALUE;
    else if (strcmp(type_str, "string") == 0) return STRING_VALUE;
    else if (strcmp(type_str, "bool") == 0) return BOOL_VALUE;
    else {
        fprintf(stderr, "Unknown type '%s' at line %d\n", type_str, yylineno);
        free_symbol_table(symbol_table);
        exit(1);
    }
}

%}

%start program

%union {
    enum EXPRESSION_TYPE {
        BOOL_EXPR,
        NUMERIC_EXPR,
        FLOAT_EXPR,
        INT_EXPR,
        FUNCTION_CALL_EXPR,
        ARRAY_ACCESS_EXPR,
        CHAR_EXPR,
        STRING_EXPR,
        IDENTIFIER_EXPR
    };
    int ival;
    float fval;
    char* sval;
    char cval;
    struct Parameter *param_list;
    struct {
        char* type;
        char* name;
    } type_id;
    struct Instruction* instruction;
    struct {
        EXPRESSION_TYPE expr_type;
        Value expr_value;
        ValueType expr_return_type;
        char* associated_identifier;
    } expr;
    struct {
        expr* e;
        expr* next_expr;
    } expr_lst;
}

%token <ival> INTEGER_LITERAL
%token <fval> FLOAT_LITERAL
%token <cval> CHARACTER_LITERAL
%token <sval> STRING_LITERAL
%token <ival> BOOLEAN_LITERAL
%token <sval> IDENTIFIER
%token <sval> INT_TYPE_KEYWORD
%token <sval> FLOAT_TYPE_KEYWORD
%token <sval> STRING_TYPE_KEYWORD
%token <sval> CHAR_TYPE_KEYWORD
%token <sval> BOOL_TYPE_KEYWORD
%token <sval> VOID_TYPE_KEYWORD
%token IF_KEYWORD
%token ELSEIF_KEYWORD
%token ELSE_KEYWORD
%token FOR_KEYWORD
%token WHILE_KEYWORD
%token SWITCH_KEYWORD
%token <sval> MAIN_KEYWORD
%token DO_KEYWORD
%token RETURN_KEYWORD
%token CASE_KEYWORD
%token CONST_KEYWORD
%token BREAK_KEYWORD
%token CONTINUE_KEYWORD
%token DEFAULT_KEYWORD
%token AND_KEYWORD
%token OR_KEYWORD
%token NOT_KEYWORD
%token OPENING_CURLY_BRACE
%token CLOSING_CURLY_BRACE
%token OPENING_PARENTHESIS
%token CLOSING_PARENTHESIS
%token OPENING_SQUARE_BRACKETS
%token CLOSING_SQUARE_BRACKETS
%token COMMA
%token ASTRISK
%token PLUS
%token MINUS
%token DIVIDE
%token MODULO
%token INCREMENT
%token DECREMENT
%token ASSIGNMENT
%token EQUAL
%token NOT_EQUAL
%token LESS_OR_EQUAL
%token GREATER_OR_EQUAL
%token LESS
%token GREATER
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_XOR
%token BITWISE_NOT
%token COLON
%token SEMICOLON
%token <sval> UNRECOGNIZED_TOKEN
%token RESERVED_IDENTIFIER
%type <sval> type
%type <type_id> type_identifier
%type <instruction> statement 
%type <instruction> statements body
%type <param_list> function_arguments
%type <expr> expression boolean_expr arithmetic_expr binary_expr arithmetic_term arithmetic_factor
%type <expr> bitwise_expr bitwise_xor_expr bitwise_and_expr bitwise_not_expr unary_expr
%type <expr> function_call array_element
%type <expr_lst> expr_list
%%

program:
    { scope_no++; } functions main_function { delete_scope(symbol_table, scope_no); scope_no--;}            
    ;

functions:
    function functions                  
    | /* empty */                       
    ;



function: type IDENTIFIER OPENING_PARENTHESIS { 
            curr_function_parameter_list = NULL; 
          } 
          function_arguments  CLOSING_PARENTHESIS { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          } 
          body {
            Value val;
            val.function = $8;  
            insert_symbol(symbol_table, $2, $1, val, FUNCTION, scope_no, 1, 0, 0, $5, yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_parameter_list = NULL;
            curr_function_parameter_list_ptr = NULL;
            curr_function_instructions_list = NULL;
          }
        | VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS { 
            curr_function_parameter_list = NULL; 
          } 
          function_arguments CLOSING_PARENTHESIS { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          } 
          body { 
            Value val;
            val.function = $8;
            insert_symbol(symbol_table, $2, $1, val, FUNCTION, scope_no, 1, 0, 0, $5, yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_parameter_list = NULL;
            curr_function_parameter_list_ptr = NULL; 
          }
        | type IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          } 
          body { 
            Value val;
            val.function = $6;
            insert_symbol(symbol_table, $2, $1, val, FUNCTION, scope_no, 1, 0, 0, NULL, yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_instructions_list = NULL; 
          }
        | VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS { 
            inside_a_function_declaration_body = 1;
            curr_function_instructions_list = NULL;  
          } 
          body { 
            Value val;
            val.function = $6;
            insert_symbol(symbol_table, $2, $1, val, FUNCTION, scope_no, 1, 0, 0, NULL, yylineno, 0);
            inside_a_function_declaration_body = 0;
            curr_function_instructions_list = NULL; 
          }
        ;

function_arguments:
        type_identifier {
            if (!curr_function_parameter_list) {
                curr_function_parameter_list = create_parameter($1.name, $1.type);
                curr_function_parameter_list_ptr = curr_function_parameter_list; // Point to the new parameter
            } else {
                curr_function_parameter_list_ptr->next = create_parameter($1.name, $1.type);
                curr_function_parameter_list_ptr = curr_function_parameter_list_ptr->next;
            }
            free($1.name);
            free($1.type);
            $$ = curr_function_parameter_list; // Set the parameter list
        }
        | function_arguments COMMA type_identifier {
            curr_function_parameter_list_ptr->next = create_parameter($3.name, $3.type);
            curr_function_parameter_list_ptr = curr_function_parameter_list_ptr->next;
            $$ = curr_function_parameter_list; // Propagate the parameter list
            free($3.name);
            free($3.type);
        }
        ;

type_identifier         : type IDENTIFIER { 
                                            $$.type = $1;
                                            $$.name = $2; 
                                          }
                        ;

type:
    INT_TYPE_KEYWORD   { $$ = $1; }                
    | FLOAT_TYPE_KEYWORD  { $$ = $1; }             
    | STRING_TYPE_KEYWORD { $$ = $1; }             
    | CHAR_TYPE_KEYWORD  { $$ = $1; }
    | BOOL_TYPE_KEYWORD  { $$ = $1; }
    ;



body:{ 
        scope_no++;
    }
    OPENING_CURLY_BRACE  
    statements 
    CLOSING_CURLY_BRACE { 
        if(!inside_a_function_declaration_body) {
            delete_scope(symbol_table, scope_no); 
        }
        scope_no--;
        $$ = $3; 
    }
    ;

statements:
    statement 
    statements {$$ = NULL;}
    | /* empty */ {$$ = NULL;}
    ;

statement: body SEMICOLON {$$ = NULL;}
         | assignment {$$ = NULL;}
         | array_assignment {$$ = NULL;}
         | return_statement {$$ = NULL;}
         | expression SEMICOLON {$$ = NULL;}
         | initialization {$$ = NULL;}
         | variable_declaration {$$ = NULL;}
         | const_initialization {$$ = NULL;}
         | if_statement {$$ = NULL;}
         | for_statement {$$ = NULL;}
         | while_statement {$$ = NULL;}
         | do_while_statement {$$ = NULL;}
         | switch_statement {$$ = NULL;}
         | function {$$ = NULL;}
         ;

if_statement            : IF_KEYWORD OPENING_PARENTHESIS  boolean_expr CLOSING_PARENTHESIS body elseif_statement else_statement 
                        ;

elseif_statement        : ELSEIF_KEYWORD OPENING_PARENTHESIS boolean_expr CLOSING_PARENTHESIS body
                        |
                        ;

else_statement          : ELSE_KEYWORD body
                        |
                        ;

for_statement           : FOR_KEYWORD OPENING_PARENTHESIS loop_start SEMICOLON boolean_expr SEMICOLON loop_update CLOSING_PARENTHESIS body
                        ;

loop_start              : assignment 
                        | initialization 
                        | 
                        ;

loop_update             : IDENTIFIER  ASSIGNMENT expression {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                              if(!result){
                                  fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                              if(result->is_function){
                                fprintf(stderr, "Cannot use function '%s' at line %d as a loop variable", $1, yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                              }
                              if(result->is_constant){
                                fprintf(stderr, "Cannot use const identifier '%s' at line %d as a loop variable", $1, yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                              }
                              if (result->value_type != $3.expr_return_type) {
                                  fprintf(stderr, "Type mismatch in loop update for '%s' at line %d\n", $1, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          }
                    | IDENTIFIER INCREMENT {
                        SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                        if (!result) {
                            fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->is_function) {
                            fprintf(stderr, "Cannot use function '%s' at line %d as a loop variable\n", $1, yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->is_constant) {
                            fprintf(stderr, "Cannot use const identifier '%s' at line %d as a loop variable\n", $1, yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->value_type != INT_VALUE && result->value_type != FLOAT_VALUE) {
                            fprintf(stderr, "Increment requires numeric operand at line %d\n", $1, yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->value_type == INT_VALUE) {
                            result->value.int_value++;
                        } else {
                            result->value.float_value++;
                        }
                    }
                    | IDENTIFIER DECREMENT {
                        SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                        if (!result) {
                            fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->is_function) {
                            fprintf(stderr, "Cannot use function '%s' at line %d as a loop variable\n", $1, yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->is_constant) {
                            fprintf(stderr, "Cannot use const identifier '%s' at line %d as a loop variable\n", $1, yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->value_type != INT_VALUE && result->value_type != FLOAT_VALUE) {
                            fprintf(stderr, "Decrement requires numeric operand at line %d\n", $1, yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        if (result->value_type == INT_VALUE) {
                            result->value.int_value--;
                        } else {
                            result->value.float_value--;
                        }
                    } 
                          | function_call
                          |
                          ;

while_statement         : WHILE_KEYWORD OPENING_PARENTHESIS boolean_expr CLOSING_PARENTHESIS body
                        ;

do_while_statement      : DO_KEYWORD body WHILE_KEYWORD OPENING_PARENTHESIS boolean_expr CLOSING_PARENTHESIS SEMICOLON
                        ;

switch_statement        : SWITCH_KEYWORD OPENING_PARENTHESIS IDENTIFIER {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, $3, scope_no);
                              if(!result){
                                  fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $3, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                              if(result->value_type != INT_VALUE){
                                fprintf(stderr, "Cannot use non-integer '%s' at line %d as a switch statement variable", $3, yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                              }
                          } 
                          CLOSING_PARENTHESIS  OPENING_CURLY_BRACE {scope_no++;} case_list default_case CLOSING_CURLY_BRACE { delete_scope(symbol_table, scope_no); scope_no--;}
                          ;

default_case            : DEFAULT_KEYWORD COLON statements
                        ;

case_list               : case_list case_statement
                        | case_statement
                        ;

case_statement          : CASE_KEYWORD INTEGER_LITERAL COLON statements
                        ;


initialization : type_identifier ASSIGNMENT expression {
                   SymbolTableEntry* result = search_symbol_table(symbol_table, $1.name, scope_no);
                   if (result) {
                       fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $1.name, yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
                   }
                   ValueType declared_type = string_to_value_type($1.type);
                   if (declared_type != $3.expr_return_type) {
                       fprintf(stderr, "Type mismatch in initialization at line %d\n", yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
                   }
                   Value val;
                   switch (declared_type) {
                       case INT_VALUE:
                       case BOOL_VALUE:
                           val.int_value = $3.expr_value.int_value;
                           break;
                       case FLOAT_VALUE:
                           val.float_value = $3.expr_value.float_value;
                           break;
                       case CHAR_VALUE:
                           val.char_value = $3.expr_value.char_value;
                           break;
                       case STRING_VALUE:
                           val.char_array = strdup($3.expr_value.char_array);
                           break;
                   }
                   insert_symbol(symbol_table, $1.name, $1.type, val, declared_type, scope_no, 0, 0, 0, NULL, yylineno, 0);
               }
               SEMICOLON
               | type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS {
                   SymbolTableEntry* result = search_symbol_table(symbol_table, $1.name, scope_no);
                   if (result) {
                       fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $1.name, yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
                   }
                   ValueType array_type;
                   ValueType element_type;
                   if (strcmp($1.type, "int") == 0 || strcmp($1.type, "bool") == 0) {
                       array_type = INT_ARRAY_VALUE;
                       element_type = INT_VALUE;
                   } else if (strcmp($1.type, "float") == 0) {
                       array_type = FLOAT_ARRAY_VALUE;
                       element_type = FLOAT_VALUE;
                   } else if (strcmp($1.type, "char") == 0) {
                       array_type = CHAR_ARRAY_VALUE;
                       element_type = CHAR_VALUE;
                   } else if (strcmp($1.type, "string") == 0) {
                       array_type = STRING_ARRAY_VALUE;
                       element_type = STRING_VALUE;
                   } else {
                       fprintf(stderr, "Unsupported array type '%s' at line %d\n", $1.type, yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
                   }

                   size_t declared_size = $3;
                   size_t provided_size = 0;
                   expr_lst* current = &$7;
                   while (current) {
                       provided_size++;
                       if (current->e->expr_return_type != element_type) {
                           fprintf(stderr, "Type mismatch in array initialization at line %d\n", yylineno);
                           free_symbol_table(symbol_table);
                           exit(1);
                       }
                       current = current->next_expr;
                   }

                   if (provided_size > declared_size) {
                       fprintf(stderr, "Too many initializers for array '%s' at line %d\n", $1.name, yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
                   }

                   Value val;
                   switch (array_type) {
                       case INT_ARRAY_VALUE:
                           val.int_array = (int*)calloc(declared_size, sizeof(int)); // Defaults to 0
                           current = &$7;
                           for (size_t i = 0; i < provided_size; i++) {
                               val.int_array[i] = current->e->expr_value.int_value;
                               current = current->next_expr;
                           }
                           break;
                       case FLOAT_ARRAY_VALUE:
                           val.float_array = (double*)calloc(declared_size, sizeof(double)); // Defaults to 0.0
                           current = &$7;
                           for (size_t i = 0; i < provided_size; i++) {
                               val.float_array[i] = current->e->expr_value.float_value;
                               current = current->next_expr;
                           }
                           break;
                       case CHAR_ARRAY_VALUE:
                           val.char_array = (char*)calloc(declared_size, sizeof(char)); // Defaults to '\0'
                           current = &$7;
                           for (size_t i = 0; i < provided_size; i++) {
                               val.char_array[i] = current->e->expr_value.char_value;
                               current = current->next_expr;
                           }
                           break;
                       case STRING_ARRAY_VALUE:
                           val.string_array = (char**)malloc(declared_size * sizeof(char*));
                           for (size_t i = 0; i < declared_size; i++) {
                               val.string_array[i] = strdup(""); // Default to ""
                           }
                           current = &$7;
                           for (size_t i = 0; i < provided_size; i++) {
                               free(val.string_array[i]);
                               val.string_array[i] = strdup(current->e->expr_value.char_array);
                               current = current->next_expr;
                           }
                           break;
                   }

                   insert_symbol(symbol_table, $1.name, $1.type, val, array_type, scope_no, 0, 0, 1, NULL, yylineno, declared_size);
               }
               SEMICOLON
               ;


const_initialization : CONST_KEYWORD type_identifier {
                           SymbolTableEntry* result = search_symbol_table(symbol_table, $2.name, scope_no);
                           if(result){
                               fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $2.name, yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }
                       }
                       ASSIGNMENT expression SEMICOLON {
                           ValueType declared_type = string_to_value_type($2.type);
                       
                           if (declared_type != $5.expr_return_type) {
                               fprintf(stderr, "Type mismatch in constant initialization at line %d\n", yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }
                       
                           Value val;
                           switch (declared_type) {
                               case INT_VALUE:
                               case BOOL_VALUE:
                                   val.int_value = $5.expr_value.int_value;
                                   break;
                               case FLOAT_VALUE:
                                   val.float_value = $5.expr_value.float_value;
                                   break;
                               case CHAR_VALUE:
                                   val.char_value = $5.expr_value.char_value;
                                   break;
                               case STRING_VALUE:
                                   val.char_array = strdup($5.expr_value.char_array);
                                   break;
                               default:
                                   fprintf(stderr, "Unsupported type in constant initialization at line %d\n", yylineno);
                                   free_symbol_table(symbol_table);
                                   exit(1);
                           }
                       
                           insert_symbol(symbol_table, $2.name, $2.type, val, declared_type, scope_no, 0, 1, 0, NULL, yylineno, 0);
                       }
                       | CONST_KEYWORD type_identifier {
                           SymbolTableEntry* result = search_symbol_table(symbol_table, $2.name, scope_no);
                           if(result){
                               fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $2.name, yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }
                       }
                       OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS SEMICOLON {
                           ValueType array_type;
                           ValueType element_type;
                           if (strcmp($2.type, "int") == 0 || strcmp($2.type, "bool") == 0) {
                               array_type = INT_ARRAY_VALUE;
                               element_type = INT_VALUE;
                           } else if (strcmp($2.type, "float") == 0) {
                               array_type = FLOAT_ARRAY_VALUE;
                               element_type = FLOAT_VALUE;
                           } else if (strcmp($2.type, "char") == 0) {
                               array_type = CHAR_ARRAY_VALUE;
                               element_type = CHAR_VALUE;
                           } else if (strcmp($2.type, "string") == 0) {
                               array_type = STRING_ARRAY_VALUE;
                               element_type = STRING_VALUE;
                           } else {
                               fprintf(stderr, "Unsupported array type '%s' at line %d\n", $2.type, yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }

                           size_t declared_size = $5;
                           size_t provided_size = 0;
                           expr_lst* current = &$9;
                           while (current) {
                               provided_size++;
                               if (current->e->expr_return_type != element_type) {
                                   fprintf(stderr, "Type mismatch in constant array initialization at line %d\n", yylineno);
                                   free_symbol_table(symbol_table);
                                   exit(1);
                               }
                               current = current->next_expr;
                           }

                           if (provided_size > declared_size) {
                               fprintf(stderr, "Too many initializers for constant array '%s' at line %d\n", $2.name, yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }

                           Value val;
                           switch (array_type) {
                               case INT_ARRAY_VALUE:
                                   val.int_array = (int*)calloc(declared_size, sizeof(int)); // Defaults to 0
                                   current = &$9;
                                   for (size_t i = 0; i < provided_size; i++) {
                                       val.int_array[i] = current->e->expr_value.int_value;
                                       current = current->next_expr;
                                   }
                                   break;
                               case FLOAT_ARRAY_VALUE:
                                   val.float_array = (double*)calloc(declared_size, sizeof(double)); // Defaults to 0.0
                                   current = &$9;
                                   for (size_t i = 0; i < provided_size; i++) {
                                       val.float_array[i] = current->e->expr_value.float_value;
                                       current = current->next_expr;
                                   }
                                   break;
                               case CHAR_ARRAY_VALUE:
                                   val.char_array = (char*)calloc(declared_size, sizeof(char)); // Defaults to '\0'
                                   current = &$9;
                                   for (size_t i = 0; i < provided_size; i++) {
                                       val.char_array[i] = current->e->expr_value.char_value;
                                       current = current->next_expr;
                                   }
                                   break;
                               case STRING_ARRAY_VALUE:
                                   val.string_array = (char**)malloc(declared_size * sizeof(char*));
                                   for (size_t i = 0; i < declared_size; i++) {
                                       val.string_array[i] = strdup(""); // Default to ""
                                   }
                                   current = &$9;
                                   for (size_t i = 0; i < provided_size; i++) {
                                       free(val.string_array[i]);
                                       val.string_array[i] = strdup(current->e->expr_value.char_array);
                                       current = current->next_expr;
                                   }
                                   break;
                           }

                           insert_symbol(symbol_table, $2.name, $2.type, val, array_type, scope_no, 0, 1, 1, NULL, yylineno, declared_size);
                       }
                       ;
    

variable_declaration    : type_identifier {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, $1.name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $1.name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                              Value val;
                              if(strcmp($1.type, INT_TYPE_KEYWORD) == 0){
                                val.int_value = 0;
                                insert_symbol(symbol_table, $1.name, $1.type, val, INT_VALUE, scope_no, 0, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp($1.type, FLOAT_TYPE_KEYWORD) == 0){
                                val.float_value = 0.0;
                                insert_symbol(symbol_table, $1.name, $1.type, val, FLOAT_VALUE, scope_no, 0, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp($1.type, STRING_TYPE_KEYWORD) == 0){
                                val.char_array = strdup("");
                                insert_symbol(symbol_table, $1.name, $1.type, val, STRING_VALUE, scope_no, 0, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp($1.type, CHAR_TYPE_KEYWORD) == 0){
                                val.char_value = '';
                                insert_symbol(symbol_table, $1.name, $1.type, val, CHAR_VALUE, scope_no, 0, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp($1.type, BOOL_TYPE_KEYWORD) == 0){
                                val.int_value = 0;
                                insert_symbol(symbol_table, $1.name, $1.type, val, INT_VALUE, scope_no, 0, 0, 0, NULL, yylineno, 0);
                              }
                              free($1.name);
                              free($1.type);
                              
                          }
                          SEMICOLON 
                          | type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, $1.name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $1.name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                              if($3 <= 0){
                                fprintf(stderr, "Cannot declare an array of size %d at line %d\n", $3, yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                              }
                              Value val;
                              if (strcmp($1.type, INT_TYPE_KEYWORD) == 0) {
                                  insert_symbol(symbol_table, $1.name, $1.type, val, INT_ARRAY_VALUE, scope_no, 0, 0, 1, NULL, yylineno, $3);
                              }else if(strcmp($1.type, FLOAT_TYPE_KEYWORD) == 0){
                                insert_symbol(symbol_table, $1.name, $1.type, val, FLOAT_ARRAY_VALUE, scope_no, 0, 0, 1, NULL, yylineno, $3);
                              }else if(strcmp($1.type, STRING_TYPE_KEYWORD) == 0){
                                insert_symbol(symbol_table, $1.name, $1.type, val, STRING_ARRAY_VALUE, scope_no, 0, 0, 1, NULL, yylineno, $3);
                              }else if(strcmp($1.type, CHAR_TYPE_KEYWORD) == 0){
                                insert_symbol(symbol_table, $1.name, $1.type, val, CHAR_ARRAY_VALUE, scope_no, 0, 0, 1, NULL, yylineno, $3);
                              }else if(strcmp($1.type, BOOL_TYPE_KEYWORD) == 0){
                                insert_symbol(symbol_table, $1.name, $1.type, val, INT_ARRAY_VALUE, scope_no, 0, 0, 1, NULL, yylineno, $3);
                              }
                              free($1.name);
                              free($1.type);
                          } 
                          SEMICOLON 
                          ;


return_statement:
    RETURN_KEYWORD expression SEMICOLON
    ;

assignment : IDENTIFIER ASSIGNMENT expression {
               SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
               if (!result) {
                   fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->is_constant) {
                   fprintf(stderr, "Cannot assign to constant '%s' at line %d\n", $1, yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->value_type == INT_ARRAY_VALUE || result->value_type == FLOAT_ARRAY_VALUE ||
                   result->value_type == CHAR_ARRAY_VALUE || result->value_type == STRING_ARRAY_VALUE) {
                   fprintf(stderr, "Cannot assign to array '%s' directly at line %d\n", $1, yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->value_type != $3.expr_return_type) {
                   fprintf(stderr, "Type mismatch in assignment at line %d\n", yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               switch (result->value_type) {
                   case INT_VALUE:
                   case BOOL_VALUE:
                       result->value.int_value = $3.expr_value.int_value;
                       break;
                   case FLOAT_VALUE:
                       result->value.float_value = $3.expr_value.float_value;
                       break;
                   case CHAR_VALUE:
                       result->value.char_value = $3.expr_value.char_value;
                       break;
                   case STRING_VALUE:
                       if (result->value.char_array) free(result->value.char_array);
                       result->value.char_array = strdup($3.expr_value.char_array);
                       break;
                   default:
                       fprintf(stderr, "Unsupported type in assignment at line %d\n", yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
               }
           }
           SEMICOLON
           ;

array_assignment : IDENTIFIER ASSIGNMENT OPENING_CURLY_BRACE expr_list CLOSING_CURLY_BRACE {
                       SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                       if (!result) {
                           fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                           free_symbol_table(symbol_table);
                           exit(1);
                       }
                       if (result->is_constant) {
                           fprintf(stderr, "Cannot assign to constant array '%s' at line %d\n", $1, yylineno);
                           free_symbol_table(symbol_table);
                           exit(1);
                       }
                       ValueType array_type = result->value_type;
                       ValueType element_type;
                       switch (array_type) {
                           case INT_ARRAY_VALUE:
                               element_type = INT_VALUE;
                               break;
                           case FLOAT_ARRAY_VALUE:
                               element_type = FLOAT_VALUE;
                               break;
                           case CHAR_ARRAY_VALUE:
                               element_type = CHAR_VALUE;
                               break;
                           case STRING_ARRAY_VALUE:
                               element_type = STRING_VALUE;
                               break;
                           default:
                               fprintf(stderr, "'%s' is not an array at line %d\n", $1, yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                       }

                       size_t array_size = result->array_length;
                       size_t provided_size = 0;
                       expr_lst* current = &$4;
                       while (current) {
                           provided_size++;
                           if (current->e->expr_return_type != element_type) {
                               fprintf(stderr, "Type mismatch in array assignment at line %d\n", yylineno);
                               free_symbol_table(symbol_table);
                               exit(1);
                           }
                           current = current->next_expr;
                       }

                       if (provided_size > array_size) {
                           fprintf(stderr, "Too many values in array assignment for '%s' at line %d\n", $1, yylineno);
                           free_symbol_table(symbol_table);
                           exit(1);
                       }

                       switch (array_type) {
                           case INT_ARRAY_VALUE:
                               if (result->value.int_array) free(result->value.int_array);
                               result->value.int_array = (int*)calloc(array_size, sizeof(int)); // Defaults to 0
                               current = &$4;
                               for (size_t i = 0; i < provided_size; i++) {
                                   result->value.int_array[i] = current->e->expr_value.int_value;
                                   current = current->next_expr;
                               }
                               break;
                           case FLOAT_ARRAY_VALUE:
                               if (result->value.float_array) free(result->value.float_array);
                               result->value.float_array = (double*)calloc(array_size, sizeof(double)); // Defaults to 0.0
                               current = &$4;
                               for (size_t i = 0; i < provided_size; i++) {
                                   result->value.float_array[i] = current->e->expr_value.float_value;
                                   current = current->next_expr;
                               }
                               break;
                           case CHAR_ARRAY_VALUE:
                               if (result->value.char_array) free(result->value.char_array);
                               result->value.char_array = (char*)calloc(array_size, sizeof(char)); // Defaults to '\0'
                               current = &$4;
                               for (size_t i = 0; i < provided_size; i++) {
                                   result->value.char_array[i] = current->e->expr_value.char_value;
                                   current = current->next_expr;
                               }
                               break;
                           case STRING_ARRAY_VALUE:
                               if (result->value.string_array) {
                                   for (size_t i = 0; i < array_size; i++) {
                                       free(result->value.string_array[i]);
                                   }
                                   free(result->value.string_array);
                               }
                               result->value.string_array = (char**)malloc(array_size * sizeof(char*));
                               for (size_t i = 0; i < array_size; i++) {
                                   result->value.string_array[i] = strdup(""); // Default to ""
                               }
                               current = &$4;
                               for (size_t i = 0; i < provided_size; i++) {
                                   free(result->value.string_array[i]);
                                   result->value.string_array[i] = strdup(current->e->expr_value.char_array);
                                   current = current->next_expr;
                               }
                               break;
                       }
                   }
                   SEMICOLON
                   ;    


expression : boolean_expr {
               $$.expr_type = BOOL_EXPR;
               $$.expr_value.int_value = $1.expr_value.int_value; // Assume boolean_expr returns 0 or 1
               $$.expr_return_type = BOOL_VALUE;
               $$.associated_identifier = NULL;
           }
           | arithmetic_expr {
               $$ = $1; // Directly propagate the expr struct from arithmetic_expr
           }
           | function_call {
               $$ = $1; // Propagate from function_call, which sets type and value
           }
           | STRING_LITERAL {
               $$.expr_type = STRING_EXPR;
               $$.expr_value.char_array = strdup($1);
               $$.expr_return_type = STRING_VALUE;
               $$.associated_identifier = NULL;
           }
           | CHARACTER_LITERAL {
               $$.expr_type = CHAR_EXPR;
               $$.expr_value.char_value = $1;
               $$.expr_return_type = CHAR_VALUE;
               $$.associated_identifier = NULL;
           }
           | array_element {
               $$ = $1; // Propagate from array_element
           }
           | IDENTIFIER {
               SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
               if (!result) {
                   fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               $$.expr_type = IDENTIFIER_EXPR;
               $$.associated_identifier = strdup($1);
               $$.expr_return_type = result->value_type;
               switch (result->value_type) {
                   case INT_VALUE:
                   case BOOL_VALUE:
                       $$.expr_value.int_value = result->value.int_value;
                       break;
                   case FLOAT_VALUE:
                       $$.expr_value.float_value = result->value.float_value;
                       break;
                   case CHAR_VALUE:
                       $$.expr_value.char_value = result->value.char_value;
                       break;
                   case STRING_VALUE:
                       $$.expr_value.char_array = strdup(result->value.char_array);
                       break;
                   case INT_ARRAY_VALUE:
                       $$.expr_value.int_array = result->value.int_array;
                       break;
                   case FLOAT_ARRAY_VALUE:
                       $$.expr_value.float_array = result->value.float_array;
                       break;
                   case CHAR_ARRAY_VALUE:
                       $$.expr_value.char_array = result->value.char_array;
                       break;
                   case STRING_ARRAY_VALUE:
                       $$.expr_value.string_array = result->value.string_array;
                       break;
                   default:
                       fprintf(stderr, "Unsupported type for identifier '%s' at line %d\n", $1, yylineno);
                       free_symbol_table(symbol_table);
                       exit(1);
               }
           }
           ;


array_element : IDENTIFIER OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS {
                    SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                    if (!result) {
                        fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if (result->value_type != INT_ARRAY_VALUE && result->value_type != FLOAT_ARRAY_VALUE &&
                        result->value_type != CHAR_ARRAY_VALUE && result->value_type != STRING_ARRAY_VALUE) {
                        fprintf(stderr, "'%s' is not an array at line %d\n", $1, yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if ($3 < 0 || $3 >= result->array_length) {
                        fprintf(stderr, "Array index out of bounds at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    $$.expr_type = ARRAY_ACCESS_EXPR;
                    $$.associated_identifier = strdup($1);
                    switch (result->value_type) {
                        case INT_ARRAY_VALUE:
                            $$.expr_return_type = INT_VALUE;
                            $$.expr_value.int_value = result->value.int_array[$3];
                            break;
                        case FLOAT_ARRAY_VALUE:
                            $$.expr_return_type = FLOAT_VALUE;
                            $$.expr_value.float_value = result->value.float_array[$3];
                            break;
                        case CHAR_ARRAY_VALUE:
                            $$.expr_return_type = CHAR_VALUE;
                            $$.expr_value.char_value = result->value.char_array[$3];
                            break;
                        case STRING_ARRAY_VALUE:
                            $$.expr_return_type = STRING_VALUE;
                            $$.expr_value.char_array = strdup(result->value.string_array[$3]);
                            break;
                        default:
                            fprintf(stderr, "Unsupported array type at line %d\n", yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                    }
                }
                ;

expr_list : expression {
              $$.e = &$1;
              $$.next_expr = NULL;
          }
          | expr_list COMMA expression {
              expr_lst* new_node = (expr_lst*)malloc(sizeof(expr_lst));
              new_node->e = &$3;
              new_node->next_expr = NULL;
              expr_lst* current = &$1;
              while (current->next_expr) {
                  current = current->next_expr;
              }
              current->next_expr = new_node;
              $$ = $1;
          }
          ;

function_call : IDENTIFIER OPENING_PARENTHESIS expr_list CLOSING_PARENTHESIS {
                    SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                    if (!result) {
                        fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if (!result->is_function) {
                        fprintf(stderr, "'%s' is not a function at line %d\n", $1, yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    Parameter* param = result->parameters;
                    expr_lst* arg = &$3;
                    while (param && arg) {
                        ValueType param_type = string_to_value_type(param->type);
                        if (param_type != arg->e->expr_return_type) {
                            fprintf(stderr, "Parameter type mismatch for '%s' at line %d\n", $1, yylineno);
                            free_symbol_table(symbol_table);
                            exit(1);
                        }
                        param = param->next;
                        arg = arg->next_expr;
                    }
                    if (param || arg) {
                        fprintf(stderr, "Incorrect number of arguments for '%s' at line %d\n", $1, yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    $$.expr_type = FUNCTION_CALL_EXPR;
                    $$.associated_identifier = strdup($1);
                    $$.expr_return_type = string_to_value_type(result->type);
                    // expr_value not set (requires execution)
                }
                | IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS {
                    SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                    if (!result) {
                        fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if (!result->is_function) {
                        fprintf(stderr, "'%s' is not a function at line %d\n", $1, yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if (result->parameters) {
                        fprintf(stderr, "'%s' expects parameters at line %d\n", $1, yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    $$.expr_type = FUNCTION_CALL_EXPR;
                    $$.associated_identifier = strdup($1);
                    $$.expr_return_type = string_to_value_type(result->type);
                }
                ;

boolean_expr : expression EQUAL arithmetic_expr {
                 if ($1.expr_return_type != $3.expr_return_type &&
                     !($1.expr_return_type == INT_VALUE && $3.expr_return_type == FLOAT_VALUE) &&
                     !($1.expr_return_type == FLOAT_VALUE && $3.expr_return_type == INT_VALUE)) {
                     fprintf(stderr, "Type mismatch in == at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression EQUAL function_call {
                 if ($1.expr_return_type != $3.expr_return_type &&
                     !($1.expr_return_type == INT_VALUE && $3.expr_return_type == FLOAT_VALUE) &&
                     !($1.expr_return_type == FLOAT_VALUE && $3.expr_return_type == INT_VALUE)) {
                     fprintf(stderr, "Type mismatch in == at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression NOT_EQUAL arithmetic_expr {
                 if ($1.expr_return_type != $3.expr_return_type &&
                     !($1.expr_return_type == INT_VALUE && $3.expr_return_type == FLOAT_VALUE) &&
                     !($1.expr_return_type == FLOAT_VALUE && $3.expr_return_type == INT_VALUE)) {
                     fprintf(stderr, "Type mismatch in != at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression NOT_EQUAL function_call {
                 if ($1.expr_return_type != $3.expr_return_type &&
                     !($1.expr_return_type == INT_VALUE && $3.expr_return_type == FLOAT_VALUE) &&
                     !($1.expr_return_type == FLOAT_VALUE && $3.expr_return_type == INT_VALUE)) {
                     fprintf(stderr, "Type mismatch in != at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression GREATER_OR_EQUAL arithmetic_expr {
                 if (($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE) ||
                     ($3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for >= at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression GREATER_OR_EQUAL function_call {
                 if (($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE) ||
                     ($3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for >= at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression LESS_OR_EQUAL arithmetic_expr {
                 if (($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE) ||
                     ($3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for <= at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression LESS_OR_EQUAL function_call {
                 if (($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE) ||
                     ($3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for <= at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression GREATER arithmetic_expr {
                 if (($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE) ||
                     ($3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for > at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression GREATER function_call {
                 if (($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE) ||
                     ($3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for > at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression LESS arithmetic_expr {
                 if (($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE) ||
                     ($3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for < at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }
             | expression LESS function_call {
                 if (($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE) ||
                     ($3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE)) {
                     fprintf(stderr, "Invalid types for < at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0; // Placeholder
             }             
             | expression AND_KEYWORD arithmetic_expr {
                 if ($1.expr_return_type != BOOL_VALUE || $3.expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "AND requires boolean operands at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0;
             }
             | expression AND_KEYWORD function_call {
                 if ($1.expr_return_type != BOOL_VALUE || $3.expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "AND requires boolean operands at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0;
             }
             | expression OR_KEYWORD arithmetic_expr {
                 if ($1.expr_return_type != BOOL_VALUE || $3.expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "OR requires boolean operands at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0;
             }
             | expression OR_KEYWORD function_call {
                 if ($1.expr_return_type != BOOL_VALUE || $3.expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "OR requires boolean operands at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0;
             }
             | NOT_KEYWORD OPENING_PARENTHESIS expression CLOSING_PARENTHESIS {
                 if ($3.expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "! requires boolean operand at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0;
             }
             | NOT_KEYWORD function_call {
                 if ($2.expr_return_type != BOOL_VALUE) {
                     fprintf(stderr, "! requires boolean operand at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.associated_identifier = NULL;
                 $$.expr_value.int_value = 0;
             }
             | BOOLEAN_LITERAL {
                 $$.expr_type = BOOL_EXPR;
                 $$.expr_return_type = BOOL_VALUE;
                 $$.expr_value.int_value = $1;
                 $$.associated_identifier = NULL;
             }
             ;


arithmetic_expr : binary_expr { $$ = $1; }
                | unary_expr { $$ = $1; }
                ;

binary_expr : binary_expr PLUS arithmetic_term {
                if ($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE ||
                    $3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE) {
                    fprintf(stderr, "Invalid types for + at line %d\n", yylineno);
                    free_symbol_table(symbol_table);
                    exit(1);
                }
                $$.expr_type = NUMERIC_EXPR;
                $$.associated_identifier = NULL;
                if ($1.expr_return_type == FLOAT_VALUE || $3.expr_return_type == FLOAT_VALUE) {
                    $$.expr_return_type = FLOAT_VALUE;
                    float left = ($1.expr_return_type == FLOAT_VALUE) ? $1.expr_value.float_value : $1.expr_value.int_value;
                    float right = ($3.expr_return_type == FLOAT_VALUE) ? $3.expr_value.float_value : $3.expr_value.int_value;
                    $$.expr_value.float_value = left + right;
                } else {
                    $$.expr_return_type = INT_VALUE;
                    $$.expr_value.int_value = $1.expr_value.int_value + $3.expr_value.int_value;
                }
            }
            | binary_expr MINUS arithmetic_term {
                if ($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE ||
                    $3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE) {
                    fprintf(stderr, "Invalid types for - at line %d\n", yylineno);
                    free_symbol_table(symbol_table);
                    exit(1);
                }
                $$.expr_type = NUMERIC_EXPR;
                $$.associated_identifier = NULL;
                if ($1.expr_return_type == FLOAT_VALUE || $3.expr_return_type == FLOAT_VALUE) {
                    $$.expr_return_type = FLOAT_VALUE;
                    float left = ($1.expr_return_type == FLOAT_VALUE) ? $1.expr_value.float_value : $1.expr_value.int_value;
                    float right = ($3.expr_return_type == FLOAT_VALUE) ? $3.expr_value.float_value : $3.expr_value.int_value;
                    $$.expr_value.float_value = left - right;
                } else {
                    $$.expr_return_type = INT_VALUE;
                    $$.expr_value.int_value = $1.expr_value.int_value - $3.expr_value.int_value;
                }
            }
            | arithmetic_term { $$ = $1; }
            ;

arithmetic_term : arithmetic_term ASTRISK arithmetic_factor {
                    if ($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE ||
                        $3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE) {
                        fprintf(stderr, "Invalid types for * at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    $$.expr_type = NUMERIC_EXPR;
                    $$.associated_identifier = NULL;
                    if ($1.expr_return_type == FLOAT_VALUE || $3.expr_return_type == FLOAT_VALUE) {
                        $$.expr_return_type = FLOAT_VALUE;
                        float left = ($1.expr_return_type == FLOAT_VALUE) ? $1.expr_value.float_value : $1.expr_value.int_value;
                        float right = ($3.expr_return_type == FLOAT_VALUE) ? $3.expr_value.float_value : $3.expr_value.int_value;
                        $$.expr_value.float_value = left * right;
                    } else {
                        $$.expr_return_type = INT_VALUE;
                        $$.expr_value.int_value = $1.expr_value.int_value * $3.expr_value.int_value;
                    }
                }
                | arithmetic_term DIVIDE arithmetic_factor {
                    if ($1.expr_return_type != INT_VALUE && $1.expr_return_type != FLOAT_VALUE ||
                        $3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE) {
                        fprintf(stderr, "Invalid types for / at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if (($3.expr_return_type == INT_VALUE && $3.expr_value.int_value == 0) ||
                        ($3.expr_return_type == FLOAT_VALUE && $3.expr_value.float_value == 0.0)) {
                        fprintf(stderr, "Division by zero at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    $$.expr_type = NUMERIC_EXPR;
                    $$.associated_identifier = NULL;
                    if ($1.expr_return_type == FLOAT_VALUE || $3.expr_return_type == FLOAT_VALUE) {
                        $$.expr_return_type = FLOAT_VALUE;
                        float left = ($1.expr_return_type == FLOAT_VALUE) ? $1.expr_value.float_value : $1.expr_value.int_value;
                        float right = ($3.expr_return_type == FLOAT_VALUE) ? $3.expr_value.float_value : $3.expr_value.int_value;
                        $$.expr_value.float_value = left / right;
                    } else {
                        $$.expr_return_type = INT_VALUE;
                        $$.expr_value.int_value = $1.expr_value.int_value / $3.expr_value.int_value;
                    }
                }
                | arithmetic_term MODULO INTEGER_LITERAL {
                    if ($1.expr_return_type != INT_VALUE) {
                        fprintf(stderr, "Modulo requires integer operand at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if ($3 == 0) {
                        fprintf(stderr, "Modulo by zero at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    $$.expr_type = NUMERIC_EXPR;
                    $$.expr_return_type = INT_VALUE;
                    $$.expr_value.int_value = $1.expr_value.int_value % $3;
                    $$.associated_identifier = NULL;
                }
                | arithmetic_term MODULO OPENING_PARENTHESIS expression CLOSING_PARENTHESIS {
                    if ($1.expr_return_type != INT_VALUE || $4.expr_return_type != INT_VALUE) {
                        fprintf(stderr, "Modulo requires integer operands at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    if ($4.expr_value.int_value == 0) {
                        fprintf(stderr, "Modulo by zero at line %d\n", yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                    $$.expr_type = NUMERIC_EXPR;
                    $$.expr_return_type = INT_VALUE;
                    $$.expr_value.int_value = $1.expr_value.int_value % $4.expr_value.int_value;
                    $$.associated_identifier = NULL;
                }
                | arithmetic_factor { $$ = $1; }
                ;

arithmetic_factor : bitwise_expr { $$ = $1; }
                  | FLOAT_LITERAL {
                      $$.expr_type = FLOAT_EXPR;
                      $$.expr_value.float_value = $1;
                      $$.expr_return_type = FLOAT_VALUE;
                      $$.associated_identifier = NULL;
                  }
                  | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS { $$ = $2; }
                  ;

bitwise_expr : bitwise_expr BITWISE_OR bitwise_xor_expr {
                 if ($1.expr_return_type != INT_VALUE || $3.expr_return_type != INT_VALUE) {
                     fprintf(stderr, "Bitwise OR requires integer operands at line %d\n", yylineno);
                     free_symbol_table(symbol_table);
                     exit(1);
                 }
                 $$.expr_type = NUMERIC_EXPR;
                 $$.expr_return_type = INT_VALUE;
                 $$.expr_value.int_value = $1.expr_value.int_value | $3.expr_value.int_value;
                 $$.associated_identifier = NULL;
             }
             | bitwise_xor_expr { $$ = $1; }
             ;

bitwise_xor_expr : bitwise_xor_expr BITWISE_XOR bitwise_and_expr {
                     if ($1.expr_return_type != INT_VALUE || $3.expr_return_type != INT_VALUE) {
                         fprintf(stderr, "Bitwise XOR requires integer operands at line %d\n", yylineno);
                         free_symbol_table(symbol_table);
                         exit(1);
                     }
                     $$.expr_type = NUMERIC_EXPR;
                     $$.expr_return_type = INT_VALUE;
                     $$.expr_value.int_value = $1.expr_value.int_value ^ $3.expr_value.int_value;
                     $$.associated_identifier = NULL;
                 }
                 | bitwise_and_expr { $$ = $1; }
                 ;

bitwise_and_expr : bitwise_and_expr BITWISE_AND bitwise_not_expr {
                     if ($1.expr_return_type != INT_VALUE || $3.expr_return_type != INT_VALUE) {
                         fprintf(stderr, "Bitwise AND requires integer operands at line %d\n", yylineno);
                         free_symbol_table(symbol_table);
                         exit(1);
                     }
                     $$.expr_type = NUMERIC_EXPR;
                     $$.expr_return_type = INT_VALUE;
                     $$.expr_value.int_value = $1.expr_value.int_value & $3.expr_value.int_value;
                     $$.associated_identifier = NULL;
                 }
                 | bitwise_not_expr { $$ = $1; }
                 ;

bitwise_not_expr : BITWISE_NOT bitwise_not_expr {
                     if ($2.expr_return_type != INT_VALUE) {
                         fprintf(stderr, "Bitwise NOT requires integer operand at line %d\n", yylineno);
                         free_symbol_table(symbol_table);
                         exit(1);
                     }
                     $$.expr_type = NUMERIC_EXPR;
                     $$.expr_return_type = INT_VALUE;
                     $$.expr_value.int_value = ~$2.expr_value.int_value;
                     $$.associated_identifier = NULL;
                 }
                 | INTEGER_LITERAL {
                     $$.expr_type = INT_EXPR;
                     $$.expr_return_type = INT_VALUE;
                     $$.expr_value.int_value = $1;
                     $$.associated_identifier = NULL;
                 }
                 ;

unary_expr : IDENTIFIER INCREMENT {
               SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
               if (!result) {
                   fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->value_type != INT_VALUE && result->value_type != FLOAT_VALUE) {
                   fprintf(stderr, "Increment requires numeric operand at line %d\n", yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->is_constant) {
                   fprintf(stderr, "Cannot increment constant '%s' at line %d\n", $1, yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               $$.expr_type = NUMERIC_EXPR;
               $$.associated_identifier = strdup($1);
               if (result->value_type == INT_VALUE) {
                   $$.expr_return_type = INT_VALUE;
                   $$.expr_value.int_value = result->value.int_value++;
               } else {
                   $$.expr_return_type = FLOAT_VALUE;
                   $$.expr_value.float_value = result->value.float_value++;
               }
           }
           | IDENTIFIER DECREMENT {
               SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
               if (!result) {
                   fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->value_type != INT_VALUE && result->value_type != FLOAT_VALUE) {
                   fprintf(stderr, "Decrement requires numeric operand at line %d\n", yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->is_constant) {
                   fprintf(stderr, "Cannot decrement constant '%s' at line %d\n", $1, yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               $$.expr_type = NUMERIC_EXPR;
               $$.associated_identifier = strdup($1);
               if (result->value_type == INT_VALUE) {
                   $$.expr_return_type = INT_VALUE;
                   $$.expr_value.int_value = result->value.int_value--;
               } else {
                   $$.expr_return_type = FLOAT_VALUE;
                   $$.expr_value.float_value = result->value.float_value--;
               }
           }
           | MINUS IDENTIFIER {
               SymbolTableEntry* result = search_symbol_table(symbol_table, $2, scope_no);
               if (!result) {
                   fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $2, yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               if (result->value_type != INT_VALUE && result->value_type != FLOAT_VALUE) {
                   fprintf(stderr, "Unary minus requires numeric operand at line %d\n", yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               $$.expr_type = NUMERIC_EXPR;
               $$.associated_identifier = NULL;
               if (result->value_type == INT_VALUE) {
                   $$.expr_return_type = INT_VALUE;
                   $$.expr_value.int_value = -result->value.int_value;
               } else {
                   $$.expr_return_type = FLOAT_VALUE;
                   $$.expr_value.float_value = -result->value.float_value;
               }
           }
           | MINUS OPENING_PARENTHESIS expression CLOSING_PARENTHESIS {
               if ($3.expr_return_type != INT_VALUE && $3.expr_return_type != FLOAT_VALUE) {
                   fprintf(stderr, "Unary minus requires numeric operand at line %d\n", yylineno);
                   free_symbol_table(symbol_table);
                   exit(1);
               }
               $$.expr_type = NUMERIC_EXPR;
               $$.associated_identifier = NULL;
               if ($3.expr_return_type == INT_VALUE) {
                   $$.expr_return_type = INT_VALUE;
                   $$.expr_value.int_value = -$3.expr_value.int_value;
               } else {
                   $$.expr_return_type = FLOAT_VALUE;
                   $$.expr_value.float_value = -$3.expr_value.float_value;
               }
           }
           | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS INCREMENT {
               fprintf(stderr, "Increment on expression not supported at line %d\n", yylineno);
               free_symbol_table(symbol_table);
               exit(1);
           }
           | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS DECREMENT {
               fprintf(stderr, "Decrement on expression not supported at line %d\n", yylineno);
               free_symbol_table(symbol_table);
               exit(1);
           }
           ;


main_function:
    MAIN_KEYWORD OPENING_PARENTHESIS CLOSING_PARENTHESIS body
    ;

%%
