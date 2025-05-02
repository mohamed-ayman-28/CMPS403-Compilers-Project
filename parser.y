%{
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*not used right now*/
void yyerror(const char *s);
int yylex(void);
extern FILE* yyin;
%}

%start program

%union {
    int ival;
    float fval;
    char* sval;
    char cval;
}

%token <ival> INTEGER_LITERAL
%token <fval> FLOAT_LITERAL
%token <char> CHARACTER_LITERAL
%token <sval> STRING_LITERAL
%token <ival> BOOLEAN_LITERAL
%token IDENTIFIER
%token INT_TYPE_KEYWORD
%token FLOAT_TYPE_KEYWORD
%token STRING_TYPE_KEYWORD
%token CHAR_TYPE_KEYWORD
%token BOOL_TYPE_KEYWORD
%token VOID_TYPE_KEYWORD
%token IF_KEYWORD
%token ELSEIF_KEYWORD
%token ELSE_KEYWORD
%token FOR_KEYWORD
%token WHILE_KEYWORD
%token SWITCH_KEYWORD
%token MAIN_KEYWORD
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


%%

program:
    functions main_function            
    ;

functions:
    function functions                  
    | /* empty */                       
    ;

function: type IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS body
        | VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS body
        | type IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS body
        | VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS body
        ;

function_arguments      : type_identifier 
                        | function_arguments COMMA type_identifier
                        ;

type_identifier         : type IDENTIFIER 
                        ;

type:
    INT_TYPE_KEYWORD                   
    | FLOAT_TYPE_KEYWORD               
    | STRING_TYPE_KEYWORD              
    | CHAR_TYPE_KEYWORD
    | BOOL_TYPE_KEYWORD
    ;

body:
    OPENING_CURLY_BRACE statements CLOSING_CURLY_BRACE
    ;

statements:
    statement statements
    | /* empty */
    ;

statement: body SEMICOLON
         | assignment
         | return_statement
         | expression SEMICOLON
         | initialization
         | variable_declaration
         | const_initialization
         | const_variable_declaration
         | if_statement
         | for_statement
         | while_statement
         | do_while_statement
         | switch_statement
         | function
         ;

if_statement            : IF_KEYWORD OPENING_PARENTHESIS boolean_expr CLOSING_PARENTHESIS body elseif_statement else_statement
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

loop_update             : IDENTIFIER ASSIGNMENT expression
                        | function_call
                        |
                        ;

while_statement         : WHILE_KEYWORD OPENING_PARENTHESIS boolean_expr CLOSING_PARENTHESIS body
                        ;

do_while_statement      : DO_KEYWORD body WHILE_KEYWORD OPENING_PARENTHESIS boolean_expr CLOSING_PARENTHESIS SEMICOLON
                        ;

switch_statement        : SWITCH_KEYWORD OPENING_PARENTHESIS IDENTIFIER CLOSING_PARENTHESIS OPENING_CURLY_BRACE case_list CLOSING_CURLY_BRACE
                        | SWITCH_KEYWORD OPENING_PARENTHESIS IDENTIFIER CLOSING_PARENTHESIS OPENING_CURLY_BRACE case_list default_case CLOSING_CURLY_BRACE
                        ;

default_case            : DEFAULT_KEYWORD COLON statements
                        ;

case_list               : case_list case_statement
                        | case_statement
                        ;

case_statement          : CASE_KEYWORD INTEGER_LITERAL COLON statements
                        ;


initialization          : type_identifier ASSIGNMENT expression SEMICOLON
                        | type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS SEMICOLON
                        ;

const_initialization    : CONST_KEYWORD type_identifier ASSIGNMENT expression SEMICOLON
                        | CONST_KEYWORD type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS SEMICOLON
                        ;

variable_declaration    : type_identifier SEMICOLON
                        | type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS SEMICOLON
                        ;

const_variable_declaration :  CONST_KEYWORD type_identifier SEMICOLON
                           | CONST_KEYWORD type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS SEMICOLON

return_statement:
    RETURN_KEYWORD expression SEMICOLON
    ;

assignment:
    IDENTIFIER ASSIGNMENT expression SEMICOLON
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

function_call : IDENTIFIER OPENING_PARENTHESIS expr_list CLOSING_PARENTHESIS
              | IDENTIFIER OPENING_PARENTHESIS CLOSING_PARENTHESIS
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

unary_expr  : IDENTIFIER INCREMENT
            | IDENTIFIER DECREMENT
            | MINUS IDENTIFIER 
            | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS INCREMENT
            | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS DECREMENT   
            | MINUS OPENING_PARENTHESIS IDENTIFIER CLOSING_PARENTHESIS                
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
                        | IDENTIFIER
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
