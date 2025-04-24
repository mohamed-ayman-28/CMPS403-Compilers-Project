%{
#include <stdio.h>
%}

%token INTEGER_LITERAL
%token FLOAT_LITERAL
%token CHARACTER_LITERAL
%token STRING_LITERAL
%token BOOLEAN_LITERAL
%token COMMENT
%token IDENTIFIER
%token INT_TYPE_KEYWORD
%token FLOAT_TYPE_KEYWORD
%token STRING_TYPE_KEYWORD
%token CHAR_TYPE_KEYWORD
%token BOOL_TYPE_KEYWORD
%token VOID_TYPE_KEYWORD
%token IF_KEYWORD
%token ELSE_KEYWORD
%token FOR_KEYWORD
%token WHILE_KEYWORD
%token SWITCH_KEYWORD
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

%left '+' '-'
%left '*' '/' '%'


%%
   expr : ;
   /*
       program                 : headers declarations global_statements main '(' ')' '{' body return '}'
                               |
                               ;
                       
       headers                 : headers import 
                               | import
                               |
                               ; 
                       
       import                  : IMPORT_KEYWORD STRING_LITERAL SEMICOLON
                               ;
       
       declarations            : declarations function_declaration 
                               | declarations variable_declaration
                               ;
       
       function_declaration    : INT_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE
                               | FLOAT_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE
                               | STRING_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE
                               | CHAR_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE
                               | BOOL_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE
                               | VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE
                               ;
       
       function_arguments      : type_identifier 
                               | function_arguments COMMA type_identifier
                               | 
                               ;
       
       
       body                    : body statement
                               | statement
                               |
                               ;
       
       statement               : assignment SEMICOLON
                               | initialization SEMICOLON
                               | declaration    SEMICOLON
                               | function_call  SEMICOLON
                               | if
                               | for
                               | while
                               | repeat_until
                               | switch
                               ;
       
       assignment              : IDENTIFIER ASSIGNMENT expr
                               | IDENTIFIER ASSIGNMENT expr_list
                               ;
       
       initialization          : type_identifier ASSIGNMENT expr
                               | type_identifier ASSIGNMENT expr_list
                               ;
       
       declaration             : type_identifier ASSIGNMENT expr
                               | type_identifier ASSIGNMENT expr_list
                               ;
       
       function_call           : IDENTIFIER OPENING_PARENTHESIS expr_list CLOSING_PARENTHESIS
                               ;
       
       expr_list               : expr
                               | expr_list COMMA expr
                               ;
       
       expr                    : arithmetic_expr
                               | bool_expr
                               | function_call
                               | bitwise_expr
                               ;
       
       arithmetic_expr         : arithmetic_expr PLUS arithmetic_term
                               | arithmetic_expr MINUS arithmetic_term
                               | arithmetic_term
       
       arithmetic_term         : arithmetic_term ASTRISK arithmetic_factor
                               | arithmetic_term DIVIDE arithmetic_factor
                               | arithmetic_factor
                               ;
       
       bool_expr               : logical_or_expression
                               ;
       
       logical_or_expression   : logical_or_expression OR_KEYWORD logical_and_expression
                               | logical_and_expression
                               ;
       
       logical_and_expression  : logical_and_expression AND_KEYWORD eqaulity_expression
                               | eqaulity_expression
                               ;
       
       eqaulity_expression     : eqaulity_expression EQUAL 
       
       arithmetic_factor       : numeric_literal 
                               | OPENING_PARENTHESIS arithmetic_expr CLOSING_PARENTHESIS
                               ;
       
       numeric_literal         : INTEGER_LITERAL
                               | FLOAT_LITERAL
                               ;
       
       type_identifier         : type IDENTIFIER 
                               ;   
       
       type                    : INT_TYPE_KEYWORD
                               | FLOAT_TYPE_KEYWORD
                               | STRING_TYPE_KEYWORD
                               | CHAR_TYPE_KEYWORD
                               | BOOL_TYPE_KEYWORD
                               | VOID_TYPE_KEYWORD
   */
%%

int main(){
    yyparse();
    return 0;
}