#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<string.h>


struct lnode{
    struct data *p;
    struct lnode *next;
};

struct data{
    double f;
    char *s[2];
};


void push(struct lnode **head, struct data *data) {
    struct lnode *tmp = malloc(sizeof(struct lnode));
    tmp->p = malloc(sizeof(struct data));
    tmp->p = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void printList(struct lnode *head) {
    struct lnode *curr = head;
    
    while (curr != NULL) {
        printf("%.2f %s %s\n", curr->p->f, curr->p->s[0], curr->p->s[1]);
        curr = curr->next;
    }
}

int llength(struct lnode *head){
  struct lnode *tmp = head;
  int len = 0;
  if(head == NULL){
    return 0 ; 
  }
  while(tmp != NULL){
    len++;
    tmp = tmp->next;
  }
  return len;
}

struct lnode** reverseList(struct lnode **head){
    int len = llength(*head);
    int n = len / 2;
    int i , j ;
    struct lnode *pt = NULL;
    struct lnode *sec_pt = NULL;
    struct data *tmp = NULL;

    for(i = 0 ; i < n ; i++){
        sec_pt = *head;
        pt = *head;
        for(j = 0 ; j < n ; j++){
            if(j - i != 0){
                pt = pt->next;
            }
            else{
                break;
            }
        }
        for(j = 0 ; j < len ; j++){
            if(j != len - i-1){
                sec_pt = sec_pt->next;
            }
            else{
                break;
            }
        }
        tmp = sec_pt->p;
        sec_pt->p = pt->p;
        pt->p = tmp;
    }
    return head;
}

void reverse(struct lnode **head) {
    struct lnode *prev = NULL;
    struct lnode *ptr = *head;
    struct lnode *next = NULL;
    while (ptr != NULL) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    *head = prev;
}



int main(int argc , char* argv[]){
    int i , j;
    double k = 1.11;
    char *s0;
    char *s1;
    int n ;
    struct lnode *head =NULL;
    struct data *p = NULL;
    scanf("%d", &n);
    for(i = 1 ; i < n +1; i++){
        p = malloc(sizeof(struct data));
        s0 = malloc(sizeof(char)*5);
        s1 = malloc(sizeof(char)*5);
        for(j = 0 ; j < 5 ; j++){
            s0[j] = 65 + i;
            s1[j] = 97 + i;
        }
        s0[j] = '\0';
        s1[j] = '\0';
        p->f = i*k;
        p->s[0]= s0;
        p->s[1]= s1;

        push(&head, p);
    }


    printf("Original list:\n");
    printList(head);
    reverseList(&head);
    printf("Reversed list:\n");
    printList(head);
    free(p);
    free(s0);
    free(s1);
    return 0;
}