%{
#include <stdio.h>
#include "parser.tab.h"

int line_count = 0;
int token_count = 0;
extern FILE* yyin;
extern int yylineno;
%}

digit                   [0-9]
letter                  [a-zA-Z]


%%
[1-9]{digit}*|-[1-9]{digit}*|0                           { printf("detected token of type INTEGER_LITERAL : %s\n", yytext); token_count++; return INTEGER_LITERAL; }
0[oO]{digit}+|-0[oO]{digit}+                             { printf("detected token of type INTEGER_LITERAL : %s\n", yytext); token_count++; return INTEGER_LITERAL; }
0[xX]{digit}+|-0[xX]{digit}+                             { printf("detected token of type INTEGER_LITERAL : %s\n", yytext); token_count++; return INTEGER_LITERAL; }
0b[01]+|-0b[01]+                                         { printf("detected token of type INTEGER_LITERAL : %s\n", yytext); token_count++; return INTEGER_LITERAL; }
"int"                                                    { printf("detected token of type INT_TYPE_KEYWORD : %s\n", yytext); token_count++; return INT_TYPE_KEYWORD; }
"main"                                                   { printf("detected token of type MAIN_KEYWORD : %s\n", yytext); token_count++; return MAIN_KEYWORD; }
"float"                                                  { printf("detected token of type FLOAT_TYPE_KEYWORD : %s\n", yytext); token_count++; return FLOAT_TYPE_KEYWORD; }
"string"                                                 { printf("detected token of type STRING_TYPE_KEYWORD : %s\n", yytext); token_count++; return STRING_TYPE_KEYWORD; }
"char"                                                   { printf("detected token of type CHAR_TYPE_KEYWORD : %s\n", yytext); token_count++; return CHAR_TYPE_KEYWORD; }
"bool"                                                   { printf("detected token of type BOOL_TYPE_KEYWORD : %s\n", yytext); token_count++; return BOOL_TYPE_KEYWORD; }
"void"                                                   { printf("detected token of type VOID_TYPE_KEYWORD : %s\n", yytext); token_count++; return VOID_TYPE_KEYWORD; }
"if"                                                     { printf("detected token of type IF_KEYWORD : %s\n", yytext); token_count++; return IF_KEYWORD; }
"elseif"                                                 { printf("detected token of type ELSEIF_KEYWORD : %s\n", yytext); token_count++; return ELSEIF_KEYWORD; }
"else"                                                   { printf("detected token of type ELSE_KEYWORD : %s\n", yytext); token_count++; return ELSE_KEYWORD; }
"for"                                                    { printf("detected token of type FOR_KEYWORD : %s\n", yytext); token_count++; return FOR_KEYWORD; }
"while"                                                  { printf("detected token of type WHILE_KEYWORD : %s\n", yytext); token_count++; return WHILE_KEYWORD; }
"switch"                                                 { printf("detected token of type SWITCH_KEYWORD : %s\n", yytext); token_count++; return SWITCH_KEYWORD; }
"case"                                                   { printf("detected token of type CASE_KEYWORD : %s\n", yytext); token_count++; return CASE_KEYWORD; }
"default"                                                { printf("detected token of type DEFAULT_KEYWORD : %s\n", yytext); token_count++; return DEFAULT_KEYWORD; }
"break"                                                  { printf("detected token of type BREAK_KEYWORD : %s\n", yytext); token_count++; return BREAK_KEYWORD; }
"continue"                                               { printf("detected token of type CONTINUE_KEYWORD : %s\n", yytext); token_count++; return CONTINUE_KEYWORD; }
"do"                                                     { printf("detected token of type DO_KEYWORD : %s\n", yytext); token_count++; return DO_KEYWORD; }
"return"                                                 { printf("detected token of type RETURN_KEYWORD : %s\n", yytext); token_count++; return RETURN_KEYWORD; }
"const"                                                  { printf("detected token of type CONST_KEYWORD : %s\n", yytext); token_count++; return CONST_KEYWORD; }
"and"                                                    { printf("detected token of type AND_KEYWORD : %s\n", yytext); token_count++; return AND_KEYWORD; }
"or"                                                     { printf("detected token of type OR_KEYWORD : %s\n", yytext); token_count++; return OR_KEYWORD; }
"not"                                                    { printf("detected token of type NOT_KEYWORD : %s\n", yytext); token_count++; return NOT_KEYWORD; }
\{                                                       { printf("detected token of type OPENING_CURLY_BRACE : %s\n", yytext); token_count++; return OPENING_CURLY_BRACE; }
\}                                                       { printf("detected token of type CLOSING_CURLY_BRACE : %s\n", yytext); token_count++; return CLOSING_CURLY_BRACE; }
\(                                                       { printf("detected token of type OPENING_PARENTHESIS : %s\n", yytext); token_count++; return OPENING_PARENTHESIS; }
\)                                                       { printf("detected token of type CLOSING_PARENTHESIS : %s\n", yytext); token_count++; return CLOSING_PARENTHESIS; }
\[                                                       { printf("detected token of type OPENING_SQUARE_BRACKETS : %s\n", yytext); token_count++; return OPENING_SQUARE_BRACKETS; }
\]                                                       { printf("detected token of type CLOSING_SQUARE_BRACKETS : %s\n", yytext); token_count++; return CLOSING_SQUARE_BRACKETS; }
{digit}+\.{digit}*|-{digit}+\.{digit}*                   { printf("detected token of type FLOAT_LITERAL : %s\n", yytext); token_count++; return FLOAT_LITERAL; }
","                                                      { printf("detected token of type COMMA : %s\n", yytext); token_count++; return COMMA; }
"*"                                                      { printf("detected token of type ASTRISK : %s\n", yytext); token_count++; return ASTRISK; }
"+"                                                      { printf("detected token of type PLUS : %s\n", yytext); token_count++; return PLUS; }
"-"                                                      { printf("detected token of type MINUS : %s\n", yytext); token_count++; return MINUS; }
"/"                                                      { printf("detected token of type DIVIDE : %s\n", yytext); token_count++; return DIVIDE; }
"%"                                                      { printf("detected token of type MODULO : %s\n", yytext); token_count++; return MODULO; }
"++"                                                     { printf("detected token of type INCREMENT : %s\n", yytext); token_count++; return INCREMENT; }
"--"                                                     { printf("detected token of type DECREMENT : %s\n", yytext); token_count++; return DECREMENT; }
"="                                                      { printf("detected token of type ASSIGNMENT : %s\n", yytext); token_count++; return ASSIGNMENT; }
"=="                                                     { printf("detected token of type EQUAL : %s\n", yytext); token_count++; return EQUAL; }
"!="                                                     { printf("detected token of type NOT_EQUAL : %s\n", yytext); token_count++; return NOT_EQUAL; }
"<="                                                     { printf("detected token of type LESS_OR_EQUAL : %s\n", yytext); token_count++; return LESS_OR_EQUAL; }
">="                                                     { printf("detected token of type GREATER_OR_EQUAL : %s\n", yytext); token_count++; return GREATER_OR_EQUAL; }
"<"                                                      { printf("detected token of type LESS : %s\n", yytext); token_count++; return LESS; }
">"                                                      { printf("detected token of type GREATER : %s\n", yytext); token_count++; return GREATER; }
"|"                                                      { printf("detected token of type BITWISE_AND : %s\n", yytext); token_count++; return BITWISE_AND; }
"&"                                                      { printf("detected token of type BITWISE_OR : %s\n", yytext); token_count++; return BITWISE_OR; }
"^"                                                      { printf("detected token of type BITWISE_XOR : %s\n", yytext); token_count++; return BITWISE_XOR; }
"!"                                                      { printf("detected token of type BITWISE_NOT : %s\n", yytext); token_count++; return BITWISE_NOT; }
":"                                                      { printf("detected token of type COLON : %s\n", yytext); token_count++; return COLON; }
";"                                                      { printf("detected token of type SEMICOLON : %s\n", yytext); token_count++; return SEMICOLON; }
\'[^\'\\]\'                                              { printf("detected token of type CHARACTER_LITERAL : %s\n", yytext); token_count++; return CHARACTER_LITERAL; }
\"([^\\\"]|\\.)*\"                                       { printf("detected token of type STRING_LITERAL : %s\n", yytext); token_count++; return STRING_LITERAL; }
("true"|"false")                                         { printf("detected token of type BOOLEAN_LITERAL : %s\n", yytext); token_count++; return BOOLEAN_LITERAL; }
"/*"([^*]|\*+[^*/])*\*+"/"                               { ; }
"//".*                                                   { ; }
({letter}|_)({digit}|{letter}|_){0,14}                   { printf("detected token of type IDENTIFIER : %s\n", yytext);   token_count++; return IDENTIFIER; }
[ \t]*                                                   { ; }
[\n]                                                     { line_count++; yylineno++; }
.                                                        { return UNRECOGNIZED_TOKEN; }
 
%%


  /* "\."                                                    { printf("detected token of type DOT : %s\n", yytext); token_count++; return DOT; } */
  /* "null"                                                   { printf("detected token of type NULL_LITERAL : %s\n", yytext); token_count++; return NULL_LITERAL; } */
  /* "delete"                                                 { printf("detected token of type DELETE_KEYWORD : %s\n", yytext); token_count++; return DELETE_KEYWORD; } */
  /* "new"                                                    { printf("detected token of type NEW_KEYWORD : %s\n", yytext); token_count++; return NEW_KEYWORD; } */
  /* "?"                                                      { printf("detected token of type QUESTION_MARK : %s\n", yytext); token_count++; return QUESTION_MARK; } */
  /* "try"                                                   { printf("detected token of type TRY_KEYWORD : %s\n", yytext); token_count++; return TRY_KEYWORD; }  */
  /* "catch"                                                 { printf("detected token of type CATCH_KEYWORD : %s\n", yytext); token_count++; return CATCH_KEYWORD; } */
  /* "throw"                                                 { printf("detected token of type THROW_KEYWORD : %s\n", yytext); token_count++; return THROW_KEYWORD; } */
  /* "global"                                                 { printf("detected token of type GLOBAL_KEYWORD : %s\n", yytext); token_count++; return GLOBAL_KEYWORD; } */
  /* "is"                                                     { printf("detected token of type IS_KEYWORD : %s\n", yytext); token_count++; return IS_KEYWORD; } */ 
  /* "import"                                                 { printf("detected token of type IMPORT_KEYWORD : %s\n", yytext); token_count++; return IMPORT_KEYWORD; } */

int yywrap(void){
    printf("lexer : number of tokens detected : %d\n", token_count);
    printf("lexer : number of lines read : %d\n", line_count);
    return 1;
}