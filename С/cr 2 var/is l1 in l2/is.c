#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<string.h>


typedef struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
} node;


int llength(node *head){
  node *tmp = head;
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

void lprint(node *head){
  node *tmp = head;
  int i = 0;
  printf("----%4d--- \n", llength(head));
  if(head == NULL){
    printf("[%p] \n", head);
    return ;
  }
  while(tmp){
    printf("data: [%4d] \n", tmp->data);
    tmp = tmp->next;
  }
  printf("------------ \n");
}


node *add_head( node *head , int data){
    node *new = NULL;
    int i ;
    if( (new = malloc (sizeof(node))) == NULL){
      perror("malloc: NULL");
      exit(2);
    }
    new->prev = NULL;
    new->data = data;
    if (head == NULL){
      new->next = NULL;
    }
    else{
      new->next = head;
      head->prev = new;
    }
    return new;
  }



int check(node *first, node *second){
    int fir_len = llength(first);
    int sec_len = llength(second);
    int i ;
    int count = 0;
    if(fir_len > sec_len){
        return -1;
    }
    else if(fir_len == sec_len){
        for(i = 0 ; i < fir_len ; i++){
            if(first->data != second->data){
                return -1;
            }
            first = first->next;
            second = second->next;
        }
        return 1;
    }
    else{
        for(i = 0 ; i < fir_len ; i++){
            while(second != NULL){
                if(second->data == first->data){
                    count++;
                    break;
                }
                second = second->next;
            }
        first = first->next;
        }
        if(count == fir_len){
            return 1;
        }
        else{
            return -1;
        }
    }
}



int main(int argc , char *argv[]){
    int answer;
    int i;
    node *first = NULL;
    node *second = NULL;
    for(i = 0 ; i < 10 ; i=i+2){
        first = add_head(first, i);
        if(i == 6){
            first = add_head(first , 15);
        }
    }
    for(i = 0 ; i < 10 ; i++){
        second = add_head(second, i);
        if(i == 1){
            second = add_head(second , 15);
        }
    }

    lprint(first);
    lprint(second);
    answer = check(first , second);
    if(answer == 1){
        printf("yes");
    }
    else{
        printf("no");
    }
}