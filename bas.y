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
    program                 : declarations INT_TYPE_KEYWORD "main" OPENING_PARENTHESIS CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE 
                            ;
                    
    
    declarations            : declarations function_declaration 
                            | declarations declaration SEMICOLON
                            | declarations initialization SEMICOLON
                            |
                            ;
    
    function_declaration    : VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE
                            | type IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE
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
                            /* | if          */
                            /* | for         */
                            /* | while       */
                            /* | do_while    */
                            /* | switch      */
                            | block_structure SEMICOLON
                            ;

    block_structure         : OPENING_CURLY_BRACE body CLOSING_CURLY_BRACE
                            ;

    declaration             : type_identifier
                            | type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS
    
    assignment              : IDENTIFIER ASSIGNMENT expr
                            | IDENTIFIER ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS
                            | IDENTIFIER OPENING_SQUARE_BRACKETS expr CLOSING_SQUARE_BRACKETS ASSIGNMENT expr
                            ;
    
    initialization          : type_identifier ASSIGNMENT expr
                            | type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS
                            ;
    
    function_call           : IDENTIFIER OPENING_PARENTHESIS expr_list CLOSING_PARENTHESIS
                            ;
    
    expr_list               : expr
                            | expr_list COMMA expr
                            |
                            ;

    expr                    : arithmetic_expr
                            | array_element
                            | bool_expr
                            | function_call
                            | bitwise_expr
                            | literal
                            ;



    array_element           : IDENTIFIER OPENING_SQUARE_BRACKETS expr CLOSING_SQUARE_BRACKETS    
                            ;


    
    arithmetic_expr         : arithmetic_expr PLUS arithmetic_term
                            | arithmetic_expr MINUS arithmetic_term
                            | arithmetic_term
                            ;
    
    arithmetic_term         : arithmetic_term ASTRISK arithmetic_factor
                            | arithmetic_term DIVIDE arithmetic_factor
                            | arithmetic_term MODULO arithmetic_factor       
                            | arithmetic_factor
                            ;
    
    arithmetic_factor       : postfix_expr
                            | MINUS arithmetic_factor                        
                            ;
    
    postfix_expr            : primary_expr
                            | primary_expr INCREMENT                         
                            | primary_expr DECREMENT                         
                            ;
    
    primary_expr            : numeric_literal
                            | array_element
                            | function_call
                            | IDENTIFIER
                            | OPENING_PARENTHESIS arithmetic_expr CLOSING_PARENTHESIS
                            ;
    



    bool_expr               : logical_or_expression
                            ;
    
    logical_or_expression   : logical_or_expression OR_KEYWORD logical_and_expression
                            | logical_and_expression
                            ;
    
    logical_and_expression  : logical_and_expression AND_KEYWORD logical_not_expression
                            | logical_not_expression
                            ;
    
    logical_not_expression  : NOT_KEYWORD logical_not_expression       /* unary not: not x */
                            | BOOLEAN_LITERAL
                            | comparison_expr
                            ;
    
    comparison_expr         : arithmetic_expr EQUAL arithmetic_expr
                            | arithmetic_expr NOT_EQUAL arithmetic_expr
                            | arithmetic_expr LESS arithmetic_expr
                            | arithmetic_expr GREATER arithmetic_expr
                            | arithmetic_expr LESS_OR_EQUAL arithmetic_expr
                            | arithmetic_expr GREATER_OR_EQUAL arithmetic_expr
                            | arithmetic_expr                         /* for cases where no comparison is done */
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
    
    bitwise_not_expr        : BITWISE_NOT bitwise_not_expr          /* Unary bitwise NOT: !x */
                            | arithmetic_expr                       /* Leaf: arithmetic expressions */
                            ;


    return                  : RETURN_KEYWORD expr
                            ;

    literal                 : numeric_literal
                            | CHARACTER_LITERAL
                            | STRING_LITERAL
                            | BOOLEAN_LITERAL
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
                            ;

%%

int main(){
    yyparse();
    return 0;
}