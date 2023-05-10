#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"

int main(int argc , char *argv[]){
    char s[SIZE];
    Tree *tree = NULL;
    LList *expr = NULL;
    if(argc < 2){
        printf("No expression \n");
        return 2;
    }
    strcpy(s , argv[1]);
    expr = makellist(s);
    printllist(expr);

    printf("Processing %s \n", s);
    tree = maketree(s , 0 , strlen(s) - 1);
    //tree->left->key = 50;
    showtree(tree , 0 );
    printf(" = %d \n", calculate(tree));

    
    return 0;
}