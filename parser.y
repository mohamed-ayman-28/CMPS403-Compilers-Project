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
%}

%start program

%union {
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
}

%token <ival> INTEGER_LITERAL
%token <fval> FLOAT_LITERAL
%token <char> CHARACTER_LITERAL
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
%token UNRECOGNIZED_TOKEN
%token RESERVED_IDENTIFIER
%type <sval> type
%type <type_id> type_identifier
%type <instruction> statement 
%type <instruction> statements body
%type <param_list> function_arguments
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
            insert_symbol(symbol_table, $2, $1, val, FUNCTION, scope_no, 1, 0, $5, yylineno, 0);
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
            insert_symbol(symbol_table, $2, $1, val, FUNCTION, scope_no, 1, 0, $5, yylineno, 0);
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
            insert_symbol(symbol_table, $2, $1, val, FUNCTION, scope_no, 1, 0, NULL, yylineno, 0);
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
            insert_symbol(symbol_table, $2, $1, val, FUNCTION, scope_no, 1, 0, NULL, yylineno, 0);
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
    statements {$$ = cur;}
    | /* empty */ {$$ = NULL;}
    ;

statement: body SEMICOLON {$$ = NULL;}
         | assignment {$$ = NULL;}
         | return_statement {$$ = NULL;}
         | expression SEMICOLON {$$ = NULL;}
         | initialization {$$ = NULL;}
         | variable_declaration {$$ = NULL;}
         | const_initialization {$$ = NULL;}
         | const_variable_declaration {$$ = NULL;}
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

loop_update             : IDENTIFIER {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                              if(!result){
                                  fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                              if(result->is_function){
                                fprintf(stderr, "Cannot use function '%s' at line %d as a loop variable", $1, yylineno);
                              }
                              if(result->is_constant){
                                fprintf(stderr, "Cannot use const identifier '%s' at line %d as a loop variable", $1, yylineno);
                              }
                          } ASSIGNMENT expression
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


initialization          : type_identifier {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, $1.name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $1.name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          } ASSIGNMENT expression SEMICOLON 
                          | type_identifier {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, $1.name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $1.name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          } OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS SEMICOLON 
                          ;

const_initialization    : CONST_KEYWORD type_identifier {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, $2.name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $2.name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                          }
                          ASSIGNMENT expression SEMICOLON 
                        | CONST_KEYWORD type_identifier {
                            SymbolTableEntry* result = search_symbol_table(symbol_table, $2.name, scope_no);
                            if(result){
                                fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $2.name, yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                            }
                        }
                        OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS SEMICOLON 
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
                                insert_symbol(symbol_table, $1.name, $1.type, val, INT_VALUE, scope_no, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp($1.type, FLOAT_TYPE_KEYWORD) == 0){
                                val.float_value = 0.0;
                                insert_symbol(symbol_table, $1.name, $1.type, val, FLOAT_VALUE, scope_no, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp($1.type, STRING_TYPE_KEYWORD) == 0){
                                val.char_array = "";
                                insert_symbol(symbol_table, $1.name, $1.type, val, STRING_VALUE, scope_no, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp($1.type, CHAR_TYPE_KEYWORD) == 0){
                                val.char_value = '';
                                insert_symbol(symbol_table, $1.name, $1.type, val, CHAR_VALUE, scope_no, 0, 0, NULL, yylineno, 0);
                              }else if(strcmp($1.type, BOOL_TYPE_KEYWORD) == 0){
                                val.int_value = 0;
                                insert_symbol(symbol_table, $1.name, $1.type, val, INT_VALUE, scope_no, 0, 0, NULL, yylineno, 0);
                              }
                              
                          }
                          SEMICOLON 
                          | type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS {
                              SymbolTableEntry* result = search_symbol_table(symbol_table, $1.name, scope_no);
                              if(result){
                                  fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $1.name, yylineno);
                                  free_symbol_table(symbol_table);
                                  exit(1);
                              }
                              Value val;
                              if(strcmp($1.type, INT_TYPE_KEYWORD) == 0){
                                val.int_value = 0;
                                insert_symbol(symbol_table, $1.name, $1.type, val, INT_VALUE, scope_no, 0, 0, NULL, yylineno, $3);
                              }else if(strcmp($1.type, FLOAT_TYPE_KEYWORD) == 0){
                                val.float_value = 0.0;
                                insert_symbol(symbol_table, $1.name, $1.type, val, FLOAT_VALUE, scope_no, 0, 0, NULL, yylineno, $3);
                              }else if(strcmp($1.type, STRING_TYPE_KEYWORD) == 0){
                                val.char_array = "";
                                insert_symbol(symbol_table, $1.name, $1.type, val, STRING_VALUE, scope_no, 0, 0, NULL, yylineno, $3);
                              }else if(strcmp($1.type, CHAR_TYPE_KEYWORD) == 0){
                                val.char_value = '';
                                insert_symbol(symbol_table, $1.name, $1.type, val, CHAR_VALUE, scope_no, 0, 0, NULL, yylineno, $3);
                              }else if(strcmp($1.type, BOOL_TYPE_KEYWORD) == 0){
                                val.int_value = 0;
                                insert_symbol(symbol_table, $1.name, $1.type, val, INT_VALUE, scope_no, 0, 0, NULL, yylineno, $3);
                              }
                          } 
                          SEMICOLON 
                          ;

const_variable_declaration :  CONST_KEYWORD type_identifier {
                                  SymbolTableEntry* result = search_symbol_table(symbol_table, $2.name, scope_no);
                                  if(result){
                                      fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $2.name, yylineno);
                                      free_symbol_table(symbol_table);
                                      exit(1);
                                  }
                              }
                              SEMICOLON 
                              | CONST_KEYWORD type_identifier {
                                  SymbolTableEntry* result = search_symbol_table(symbol_table, $2.name, scope_no);
                                  if(result){
                                      fprintf(stderr, "Cannot re-declare identifier '%s' at line %d\n", $2.name, yylineno);
                                      free_symbol_table(symbol_table);
                                      exit(1);
                                  }
                              }
                             OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS SEMICOLON 
                             ;

return_statement:
    RETURN_KEYWORD expression SEMICOLON
    ;

assignment:
    IDENTIFIER {
        SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
        if(!result){
            fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
            free_symbol_table(symbol_table);
            exit(1);
        }
    } ASSIGNMENT expression  SEMICOLON 
    ;

expression : boolean_expr 
           | arithmetic_expr 
           | function_call
           | STRING_LITERAL 
           | CHARACTER_LITERAL
           | array_element
           ;

array_element : IDENTIFIER OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS    
              ;

expr_list : expression
          | expr_list COMMA expression 
          ;

function_call : IDENTIFIER {
                    SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                    if(!result){
                        fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                }
                OPENING_PARENTHESIS expr_list CLOSING_PARENTHESIS 
                | IDENTIFIER {
                    SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                    if(!result){
                        fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                        free_symbol_table(symbol_table);
                        exit(1);
                    }
                } OPENING_PARENTHESIS CLOSING_PARENTHESIS 
                ;

boolean_expr : expression EQUAL arithmetic_expr
             | expression EQUAL function_call
             | expression NOT_EQUAL arithmetic_expr
             | expression NOT_EQUAL function_call
             | expression GREATER_OR_EQUAL arithmetic_expr
             | expression GREATER_OR_EQUAL function_call
             | expression LESS_OR_EQUAL arithmetic_expr
             | expression LESS_OR_EQUAL function_call
             | expression GREATER arithmetic_expr
             | expression GREATER function_call
             | expression LESS arithmetic_expr
             | expression LESS function_call
             | expression AND_KEYWORD arithmetic_expr
             | expression AND_KEYWORD function_call
             | expression OR_KEYWORD arithmetic_expr
             | expression OR_KEYWORD function_call
             | NOT_KEYWORD OPENING_PARENTHESIS expression CLOSING_PARENTHESIS
             | NOT_KEYWORD function_call
             | BOOLEAN_LITERAL
             ;


arithmetic_expr : binary_expr
                | unary_expr
                ;

unary_expr  : IDENTIFIER {
                SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                if(!result){
                    fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                    free_symbol_table(symbol_table);
                    exit(1);
                }
            } INCREMENT
            | IDENTIFIER {
                SymbolTableEntry* result = search_symbol_table(symbol_table, $1, scope_no);
                if(!result){
                    fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $1, yylineno);
                    free_symbol_table(symbol_table);
                    exit(1);
                }
            } DECREMENT
            | MINUS IDENTIFIER {
                SymbolTableEntry* result = search_symbol_table(symbol_table, $2, scope_no);
                if(!result){
                    fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $2, yylineno);
                    free_symbol_table(symbol_table);
                    exit(1);
                }
            }
            | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS INCREMENT
            | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS DECREMENT                
            ;


binary_expr     : binary_expr PLUS arithmetic_term
                | binary_expr MINUS arithmetic_term
                | arithmetic_term
                ;

arithmetic_term         : arithmetic_term ASTRISK arithmetic_factor
                        | arithmetic_term DIVIDE arithmetic_factor
                        | arithmetic_term MODULO INTEGER_LITERAL
                        | arithmetic_term MODULO OPENING_PARENTHESIS expression CLOSING_PARENTHESIS
                        | arithmetic_factor       
                        ;

arithmetic_factor       : bitwise_expr
                        | FLOAT_LITERAL
                        | IDENTIFIER {
                            SymbolTableEntry* result = search_symbol_table(symbol_table, $2, scope_no);
                            if(!result){
                                fprintf(stderr, "Undeclared identifier '%s' at line %d\n", $2, yylineno);
                                free_symbol_table(symbol_table);
                                exit(1);
                            }
                        }
                        | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS
                        ;

bitwise_expr            : bitwise_expr BITWISE_OR bitwise_xor_expr
                        | bitwise_xor_expr
                        ;
bitwise_xor_expr        : bitwise_xor_expr BITWISE_XOR bitwise_and_expr
                        | bitwise_and_expr
                        ;

bitwise_and_expr        : bitwise_and_expr BITWISE_AND bitwise_not_expr
                        | bitwise_not_expr
                        ;

bitwise_not_expr        : BITWISE_NOT bitwise_not_expr          
                        | INTEGER_LITERAL                      
                        ;



main_function:
    MAIN_KEYWORD OPENING_PARENTHESIS CLOSING_PARENTHESIS body
    ;

%%
