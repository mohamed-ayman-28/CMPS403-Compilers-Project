%{
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool main_defined = false; // Flag to track if main has been defined

void yyerror(const char *s);
int yylex(void);
%}

%token INTEGER_LITERAL
%token FLOAT_LITERAL
%token CHARACTER_LITERAL
%token STRING_LITERAL
%token BOOLEAN_LITERAL
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

%left PLUS MINUS
%left ASTRISK DIVIDE MODULO

%%
    program                 : declarations INT_TYPE_KEYWORD MAIN_KEYWORD OPENING_PARENTHESIS CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE 
                            {
                                if (main_defined) {
                                    yyerror("Error: Multiple definitions of main function");
                                } else {
                                    main_defined = true;
                                }
                            }
                            ;
                    
    
    declarations            : declarations function_declaration 
                            | declarations declaration SEMICOLON
                            | declarations initialization SEMICOLON
                            |
                            ;
    
    function_declaration    : VOID_TYPE_KEYWORD IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE
                            {
                                if (strcmp($2, "main") == 0) {
                                    yyerror("Error: main function must have int return type");
                                }
                            }
                            | type IDENTIFIER OPENING_PARENTHESIS function_arguments CLOSING_PARENTHESIS OPENING_CURLY_BRACE body return CLOSING_CURLY_BRACE
                            {
                                if (strcmp($2, "main") == 0) {
                                    if (main_defined) {
                                        yyerror("Error: Multiple definitions of main function");
                                    } else if ($1 != INT_TYPE_KEYWORD) {
                                        yyerror("Error: main function must have int return type");
                                    } else {
                                        main_defined = true;
                                    }
                                }
                            }
                            ;
    
    function_arguments      : type_identifier 
                            | function_arguments COMMA type_identifier
                            | 
                            ;
    
    
    body                    : body statement
                            | statement
                            |
                            ;
    
    statement               : if
                            | non_loop_non_if_statement
                            | loop_statement
                            ;

    
    non_if_statement        : assignment SEMICOLON
                            | initialization SEMICOLON
                            | declaration SEMICOLON
                            | function_call SEMICOLON    
                            | for        
                            | while       
                            | do_while    
                            | switch     
                            | block_structure SEMICOLON
                            | error_token SEMICOLON
                            ;

    error_token             : UNRECOGNIZED_TOKEN 
                            { 
                                fprintf(stderr, "Error: Unrecognized token\n"); 
                            }
                            | RESERVED_IDENTIFIER
                            { 
                                fprintf(stderr, "Error: Reserved identifier used\n"); 
                            }
                            ;

    block_structure         : OPENING_CURLY_BRACE body CLOSING_CURLY_BRACE
                            ;

    const                   : CONST_KEYWORD
                            | 
                            ;
    

    declaration             : const type_identifier
                            | const type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS
                            ;
    
    assignment              : IDENTIFIER ASSIGNMENT expr
                            | IDENTIFIER ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS
                            | IDENTIFIER OPENING_SQUARE_BRACKETS expr CLOSING_SQUARE_BRACKETS ASSIGNMENT expr
                            ;
    
    initialization          : const type_identifier ASSIGNMENT expr
                            | const type_identifier OPENING_SQUARE_BRACKETS INTEGER_LITERAL CLOSING_SQUARE_BRACKETS ASSIGNMENT OPENING_SQUARE_BRACKETS expr_list CLOSING_SQUARE_BRACKETS
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
                            | arithmetic_expr                      
                            ;

    return                  : RETURN_KEYWORD expr SEMICOLON
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

    /* Unambiguous if-else grammar */
    if                      : matched_statement
                            | unmatched_statement
                            ;

    matched_statement       : IF_KEYWORD OPENING_PARENTHESIS bool_expr CLOSING_PARENTHESIS matched_statement ELSE_KEYWORD matched_statement /* one if */
                            | non_if_statements
                            ;
    non_if_statements       : non_if_statement
                            | non_if_statements non_if_statement
                            ;

    unmatched_statement     : IF_KEYWORD OPENING_PARENTHESIS bool_expr CLOSING_PARENTHESIS body
                            | IF_KEYWORD OPENING_PARENTHESIS bool_expr CLOSING_PARENTHESIS matched_statement ELSE_KEYWORD unmatched_statement
                            ;

    if_in_loop              : matched_if_in_loop
                            | unmatched_if_in_loop
                            ;

    matched_if_in_loop      : IF_KEYWORD OPENING_PARENTHESIS bool_expr CLOSING_PARENTHESIS loop_block ELSE_KEYWORD matched_if_in_loop
                            | non_if_statements
                            ;

    unmatched_if_in_loop    : IF_KEYWORD OPENING_PARENTHESIS bool_expr CLOSING_PARENTHESIS loop_block
                            | IF_KEYWORD OPENING_PARENTHESIS bool_expr CLOSING_PARENTHESIS matched_if_in_loop ELSE_KEYWORD unmatched_if_in_loop
                            ;

    loop_block              : OPENING_CURLY_BRACE  body break_or_continue CLOSING_CURLY_BRACE
                            ;

    
    loop_body_statement     : if_in_loop
                            | non_loop_non_if_statement
                            | loop_statement
                            ;
                            
    non_loop_non_if_statement : assignment SEMICOLON
                            | initialization SEMICOLON
                            | declaration SEMICOLON
                            | function_call SEMICOLON    
                            | block_structure SEMICOLON
                            | error_token SEMICOLON
                            | switch
                            ;
    loop_statement          : for
                            | while
                            | do_while
                            ;




    break_or_continue       : BREAK_KEYWORD SEMICOLON
                            | CONTINUE_KEYWORD SEMICOLON
                            |
                            ;

    loop_body_statements    : loop_body_statement
                            | loop_body_statements loop_body_statement
                            ;
    
    for                     : FOR_KEYWORD OPENING_PARENTHESIS loop_start SEMICOLON bool_expr SEMICOLON assignment CLOSING_PARENTHESIS OPENING_CURLY_BRACE loop_body_statements CLOSING_CURLY_BRACE
                            ;

    loop_start              : assignment 
                            | initialization 
                            ;

    while                   : WHILE_KEYWORD OPENING_PARENTHESIS bool_expr CLOSING_PARENTHESIS OPENING_CURLY_BRACE loop_body_statements CLOSING_CURLY_BRACE
                            ;

    do_while                : DO_KEYWORD OPENING_CURLY_BRACE loop_body_statements CLOSING_CURLY_BRACE WHILE_KEYWORD OPENING_PARENTHESIS bool_expr CLOSING_PARENTHESIS SEMICOLON
                            ;

    switch                  : SWITCH_KEYWORD OPENING_PARENTHESIS expr CLOSING_PARENTHESIS OPENING_CURLY_BRACE case_list CLOSING_CURLY_BRACE
                            | SWITCH_KEYWORD OPENING_PARENTHESIS expr CLOSING_PARENTHESIS OPENING_CURLY_BRACE case_list DEFAULT_KEYWORD COLON body CLOSING_CURLY_BRACE
                            ;

    case_list               : case_list case_statement
                            | case_statement
                            |
                            ;

    case_statement          : CASE_KEYWORD IDENTIFIER COLON body
                            | CASE_KEYWORD literal COLON body
                            ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main() {
    yyparse();
    return 0;
}