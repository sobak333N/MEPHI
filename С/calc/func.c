#include <stdio.h>
#include <stdlib.h>
//#include <error.h>
#include <string.h>
#include "def.h"

Tree *create(unsigned char key) {
    Tree *tmp;
    if ((tmp = malloc(sizeof(Tree))) == NULL) {
        perror("malloc: ");
        exit(1);
    }
    tmp->key = key;
    tmp->parent = NULL;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

Tree *add(Tree *root, unsigned char key) {
    Tree *rtmp = root;
    Tree *rsave = NULL;
    Tree *tmp;
    if ((tmp = malloc(sizeof(Tree))) == NULL) {
        perror("malloc: ");
        exit(1);
    }
    tmp->key = key;
    while (rtmp != NULL) {
        rsave = rtmp;
        if (key < rtmp->key)
            rtmp = rtmp->left;
        else
            rtmp = rtmp->right;
    }
    tmp->parent = rsave;
    tmp->left = NULL;
    tmp->right = NULL;
    if (key < rsave->key)
        rsave->left = tmp;
    else
        rsave->right = tmp;
    return root;
}

Tree *search(Tree *root, unsigned char key) {
    if ((root == NULL) || (root->key == key))
        return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

Tree *min(Tree *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

void delete(Tree *del) {
    Tree *tmp;
    if (del == NULL)
        return;
    if ((del->left == NULL) && (del->right == NULL)) {
        if (del == del->parent->right)
            del->parent->right = NULL;
        else
            del->parent->left = NULL;
        free(del);
        return;
    }
    if ((del->left == NULL) && (del->right != NULL)) {
        if (del == del->parent->right) {
            del->parent->right = del->right;
            del->parent->right->parent = del->parent;
        } else {
            del->parent->left = del->right;
            del->parent->left->parent = del->parent;
        }
        free(del);
        return;
    }
    if ((del->left != NULL) && (del->right == NULL)) {
        if (del == del->parent->right) {
            del->parent->right = del->left;
            del->parent->right->parent = del->parent;
        } else {
            del->parent->left = del->left;
            del->parent->left->parent = del->parent;
        }
        free(del);
        return;
    }
    if ((del->left != NULL) && (del->right != NULL)) {
        tmp = min(del->right);
        del->key = tmp->key;
        delete(tmp);
    }
}

void showtree(Tree *root, int p) {
    int i;
    if (root == NULL)
        return;
    p += 5;
    showtree(root->right, p);
    printf("\n");
    for (i = 5; i < p; i++)
        printf(" ");
    printf("%c\n", root->key);
    showtree(root->left, p);
}

int lastop(char expr[], int first , int last){
    unsigned char min , prt;
    int i , k;
    min = MPRT;
    for( i = first ; i <= last ; i++){
        prt = priority(expr[i]);
        if(prt <= min){
            min = prt;
            k = i;
        }
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
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}


Tree *leaf(char c){
    Tree *tmp;
    tmp = tnew();
    tmp->key = c;
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


Tree *maketree(char expr[], int first , int last){
    Tree *root;
    int k;
    if (first == last){
        return leaf(expr[first]);
    }
    k = lastop(expr , first , last);
    root = tnew();
    root->key = expr[k];
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
  tmp = tmp->next;
  while(tmp){

    printf("%s \n",tmp->lec);
    tmp = tmp->next;
  }
}



