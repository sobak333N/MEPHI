#include <stdlib.h>
#include <time.h>
#include "tittle.h"
#include <stdio.h>

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
    printf("[%14p]<-[%14p]->[%14p] ", tmp->prev , tmp, tmp->next);
    printf("data: [%4ld] s: [", tmp->data);
    for(i = 0 ; i < N ; i++){
      printf("%c", tmp->s[i]);
    }
    printf("] \n");
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
    for(i = 0; i < N; i++){
      new->s[i] = ((char)(65 + rand()%25));
    }
    if (head == NULL){
      new->next = NULL;
    }
    else{
      new->next = head;
      head->prev = new;
    }
    return new;
  }



  node *del_head(node *head){
    node *tmp = head;
    if (head == NULL){
      return NULL;
    }
    if(head->next == NULL){
      free(head);
      return NULL;
    }
    head = head->next;
    head->prev = NULL;
    free(tmp);
    return head;
  }

  node *del_tail(node *head){
    node *tmp = head;
    if(head == NULL){
      return NULL;
    }
    if (head->next==NULL){
      free(head);
      return NULL;
    }
    while (tmp->next->next){
      tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
    return head;
  }

  node *add_tail(node *head, int data, node *first){
    node *new =NULL;
    node *tmp = head;
    int i;
    if( (new = malloc(sizeof(node))) == NULL){
    perror("malloc: NULL");
    exit(3);
  }
  new->data = data;
  for(i = 0 ; i< N ; i++){
    new->s[i] = first->s[i];
  }
  new->next = NULL;
  if(head == NULL){
    new->prev = NULL;
    return new;
  }
  else{
    while(tmp->next != NULL){
      tmp = tmp->next;
    }
    tmp->next = new;
    tmp->prev = tmp;
  }
  return head;
  }

  node *sort(node* head){

    int len;
    int max = 0;
    char tmp_maxA[N];
    char tmp_lastA[N];
    int tmp_last = 0;
    node *pt = NULL;
    if ( ( len = llength(head) )== 0){
      perror("len = 0");
      exit(3);
    }

    if( (pt = malloc(sizeof(node))) == NULL){
    perror("malloc: NULL");
    exit(3);
    }
    node *sec_pt = NULL;
    if( (sec_pt = malloc(sizeof(node))) == NULL){
    perror("malloc: NULL");
    exit(3);
    }
    node *tmp = head;
    int k = 0;
    for(int i = 0; i < len ; i++){
      while(k != len - i && tmp !=NULL){
        if(tmp->data > max){
          max = tmp->data;
          pt = tmp;
        }
        sec_pt = tmp;
        tmp = tmp->next;
        k++;
        
      }
      tmp = sec_pt;
      tmp_last = sec_pt->data;
      tmp->data = max;
      for(int j = 0; j < N ; j ++){
        tmp_lastA[j] = sec_pt->s[j];
      }
      tmp = pt;
      tmp->data = tmp_last;
      for(int j = 0; j < N; j++){
        tmp_maxA[j] = tmp->s[j];
      }
      for(int j = 0; j < N; j++){
        tmp->s[j] = tmp_lastA[j];
      }
    tmp = sec_pt;
    for(int j = 0; j < N; j++){
      tmp->s[j] = tmp_maxA[j];
    }

     tmp = head;
     max = tmp->data;
     k = 0;
     pt = head ;
     sec_pt = head;
    }
   return tmp;
  }

void writefile(const char *path, node *head){
    FILE *fi;
    int k ;
    node *tmp = head;

    if((fi = fopen(path, "w")) == NULL) exit(1);
    while(tmp != NULL){
      fprintf(fi, "%d %s \n", tmp->data, tmp->s );
      tmp = tmp->next;
    }
    fprintf(fi, "\n" );
    fclose(fi);
}




node *third( node *first , node *second){
    int fir_len = llength(first);
    int sec_len = llength(second);
    int i;
    int j;
    int k;
    int count = 0;
    node *new =NULL;
    node *fir_tmp = first;
    node *sec_tmp = second;
    for( i = 0 ; i < fir_len ; i ++){
        
        for( j = 0 ; j < sec_len ; j++){
            if(fir_tmp->data != sec_tmp->data){
                count++;
            }
            sec_tmp = sec_tmp->next;

        }
        if(count == sec_len){
            new = add_tail(new , fir_tmp->data , fir_tmp);
        }
        count = 0 ;
        sec_tmp = second;
        fir_tmp = fir_tmp->next;
    }





    return new;
}