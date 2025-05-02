#include <stdio.h>
#include "parser.tab.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

int main(int argc, char** argv){
    if(argc < 2){
        printf("Missing input file\n");
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    yyin = file;
    int ntoken;
    ntoken = yylex();
    while(ntoken){
        if(ntoken == UNRECOGNIZED_TOKEN){
            printf("lexical analyzer (error): unrecognized toke %s at line %d\n", yytext, yylineno);
            return 1;
        }else if(ntoken == RESERVED_IDENTIFIER){
            printf("lexical analyzer (warning): %s at line %d is a reserved identifier\n", yytext, yylineno);
        }
        ntoken = yylex();
    }
    fclose(file);
    return 0;
}
