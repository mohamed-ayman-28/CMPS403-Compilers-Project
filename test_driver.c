#include <stdio.h>
#include <stdlib.h>

extern int yyparse();
extern FILE *yyin;

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Error opening file");
            return 1;
        }
    }

    int result = yyparse();
    
    if (argc > 1) {
        fclose(yyin);
    }
    
    return result;
}
