#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
};
void printllist(struct ListNode *head){
  struct ListNode *tmp = head;
  //tmp = tmp->next;
  while(tmp){

    printf("%d \n",tmp->val);
    tmp = tmp->next;
  }
  printf("-------------------\n");
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* firsttmp = NULL;
    struct ListNode* tmp = head;
    struct ListNode* help = NULL;
    struct ListNode* secondtmp = NULL;
    if(left > 1){
        for(int i = 0 ; i < left-2 ; i++){
            tmp = tmp->next;
        }
        help = tmp;
        tmp = tmp->next;
        firsttmp = tmp;
        for(int i = left-1 ; i < right-1 ; i++){
            tmp = tmp->next;
        }
        secondtmp = tmp->next;
        struct ListNode* prev = secondtmp;
        struct ListNode* ptr = firsttmp;
        struct ListNode* next = NULL;
        for(int i = 0 ; i < right - left+1; i++){
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        firsttmp = prev;
        help->next = firsttmp;
        return head;
    }
    else{
        firsttmp = tmp;
        for(int i = left-1 ; i < right-1 ; i++){
            tmp = tmp->next;
        }
        secondtmp = tmp->next;
        struct ListNode* prev = secondtmp;
        struct ListNode* ptr = firsttmp;
        struct ListNode* next = NULL;
        for(int i = 0 ; i < right - left+1; i++){
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        return prev;
    }
}



struct ListNode* push(struct ListNode *head, int val) {
    struct ListNode *tmp = malloc(sizeof(struct ListNode));
    struct ListNode *copy = malloc(sizeof(struct ListNode));
    copy->val = val;
    copy->next = NULL;
    tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = copy;
    return head;
}


int main(){
    struct ListNode *head = malloc(sizeof(struct ListNode));
    struct ListNode *second = malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;
    for(int i = 0 ; i < 10 ; i++){
        head = push(head , i+2);
    }
    printllist(head);
    head = reverseBetween(head, 1 , 5);
    printllist(head);
    return 0;
}