#include <stdio.h>
#include <stdlib.h>
//#include <error.h>
#include <string.h>
#include "def.h"


void showtree(Tree *root, int p) {
    int i;
    if (root == NULL)
        return;
    p += 5;
    showtree(root->right, p);
    printf("\n");
    for (i = 5; i < p; i++)
        printf(" ");
    if(root->key)
        printf("%c\n", root->key);
    else{
        printf("%d\n", root->value);
    }
    showtree(root->left, p);
}

int lastop(LList *expr, int first , int last){
    unsigned char min , prt;
    LList* tmp = expr;
    int i , k;
    min = MPRT;
    for( i = first ; i <= last ; i++){
        prt = priority(tmp->lec);
        if(prt <= min){
            min = prt;
            k = i;
        }
        tmp = tmp->next;
    }
    return k;
}

unsigned char priority(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return MPRT;
}

Tree *tnew(void){
    Tree *tmp;
    if( (tmp = malloc(sizeof(Tree))) == NULL){
        perror("malloc:");
        exit(1);
    }
    tmp->key = 0;
    tmp->value = 0;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}


Tree *leaf(int c){
    Tree *tmp;
    tmp = tnew();
    tmp->value = c;
    return tmp;
}

int power(int first, int second){
    int i ;
    int answer = first;
    for(i = 0; i < second ; i++){
        answer *= first;
    }
    return answer;
}

int calculate(Tree *root){
    int num1 , num2;
    if(!(root->left)){
        return root->key - 0x30;
    }
    num1 = calculate(root->left);
    num2 = calculate(root->right);
    switch(root->key){
        case '+': return num1+num2;
        case '-': return num1-num2; 
        case '*': return num1*num2;
        case '/': return num1/num2;
        case '^': return power(num1, num2);
    }
    return 0xffffffff;
}


Tree *maketree(LList *expr, int first , int last){
    Tree *root;
    LList *tmp = expr;
    int k;
    int i;
    if (first == last){
        for(i = 0 ; i < first ; i++){
            expr = expr->next;
        }
        return leaf(expr->lec);
    }
    k = lastop(expr , first , last);
    root = tnew();
    for(int j = 0 ; j < k ; j++){
        expr = expr->next;
    }
    root->value = atoi(expr->lec);
    root->left = maketree(expr , first , k-1);
    root->right = maketree(expr , k+1 , last);
    return root;
}


LList *makellist(char *s){
    LList *expr = NULL;
    char n[2] = {'\0' , '\0'};
    char p[1] = {'\0'};
    char *num;
    if( (num = malloc(128)) == NULL){
        perror("malloc: ");
        exit(1);
    }
    strcpy(num, p);
    while(*s){
        n[0] = *s;
        switch(*s){
            case '(':
            case ')':
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':   
                if(*num){
                expr = ladd(expr , num);
                strcpy(num, p);
                }
                expr = ladd(expr, n); break;
            case '0'...'9' : strcat(num , n); 
            break;
        }
        s++;
    }
    if (*num){
        expr = ladd(expr , num);
    }
    return expr;
}



LList *lnew(void){
    LList *tmp;
    if( (tmp = malloc(sizeof(LList))) == NULL){
        perror("malloc:");
        exit(1);
    }
    tmp->lec = 0;
    tmp->next = NULL;
    return tmp;
}

LList *ladd(LList *list , char *s){
    LList *tmp, *bak = list;
    tmp = lnew();
    if( (tmp->lec = malloc(sizeof(LList))) == NULL){
        perror("malloc:");
        exit(1);
    }
    strcpy(tmp->lec, s);
    if(list == NULL){
        return tmp;
    }
    else{
        while(list->next!=NULL){
            list = list->next;
        }
        list->next = tmp;
    }
    return bak;
}

void printTree(Tree *root, int h) {
    if (root) {
        printTree(root->right, h+1);
        for(int i = 0; i < 4 * h; ++i){
            printf(" ");
        }
        printf("%c\n", root->key);
        printTree(root->left, h+1);
    }
}


void printllist(LList *head){
  LList *tmp = head;
  //tmp = tmp->next;
  while(tmp){

    printf("%s \n",tmp->lec);
    tmp = tmp->next;
  }
}
