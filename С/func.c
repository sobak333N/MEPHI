#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "func.h"

void st_rand(struct st1 *tmp, int n){
  int k , j ;

  srand(time(NULL));
  for(k = 0 ; k < n ; k++){

    (tmp+k )-> i = rand()%100;
    for(j = 0 ; j < STRSIZE; j++){
        (tmp +k) -> s[j] = ((char)(65+rand()%25));
    }
    (tmp + k) -> s[STRSIZE] = '\0';
  }
}

void st_print(struct st1 tmp[], int n){
  int k;
  for(k=0; k < n ; k++)
    printf("%d -> [%2d][%s] \n", k , tmp[k].i , (tmp+k)-> s);

}

struct st1 *st_rand1(int n){
  int c;
  char *s;
  struct st1 *tmp , *new;

  if((tmp = new  = malloc(n*sizeof(struct st1))) == NULL){
    printf("malloc: NULL \n");
    exit(2);

  }
  sleep(1);
  srand(time(NULL));
  for(;n--; tmp++){
    tmp -> i=rand()%100;
    for(c = STRSIZE , s = tmp->s; c-- ; *s++ = (char)(65+rand()%25))
      *s = '\0';
  }
  return new;
}

void file_w( char *file , struct st1 *st, int n){
  FILE *fi;
  int k ;
  if((fi = fopen(file, "w")) == NULL) exit(1);
  for (k = 0; k < n ;k++){
    fprintf(fi, "%d %s \n", (st+k)->i, (st+k)->s );
  }
  fprintf(fi, "\n" );
  fclose(fi);
}

void file_a( char *file , struct st1 *st, int n){
  FILE *fi;
  int k ;
  if((fi = fopen(file, "a")) == NULL) exit(1);
  for (k = 0; k < n ;k++){
    fprintf(fi, "%d %s \n", (st+k)->i, (st+k)->s );
  }
  fclose(fi);
}

void st_sort(struct st1 *tmp, int n){
  int i = 1 , k, c;
  char t[STRSIZE];
  for(i ; i < n ; i++){
    int j = i ;
    while( ( (tmp+j)-> i ) < ( (tmp+j-1)-> i ) && j > 0){
      k = ( (tmp+j)-> i );
      ( (tmp+j)-> i ) = ( (tmp+j-1)-> i );
      ( (tmp+j-1)-> i ) = k;

      for(int c = 0 ; c < STRSIZE ; c++){
        t[c] = ( (tmp+j)-> s[c] );
        ( (tmp+j)-> s[c] ) = ( (tmp+j-1)-> s[c] );
        ( (tmp+j-1)-> s[c] ) = t[c];
      }
      j--;
    }
  }
}

struct st1 *file_r(char *file, int *size){
  FILE *fi;
  char a;
  int n = -1;
  int count = 0;
  struct st1 *tmp, *new, *even, *new_even;

  if((fi=fopen(file, "r")) == NULL) exit(1);
  while( (a=fgetc(fi)) != EOF) if (a == '\n') n++;
  rewind(fi);
  if((tmp=new=malloc(n*sizeof(struct st1))) == NULL){
    printf("malloc:NULL \n");
    exit(2);
  }
  while( ( (fscanf(fi, "%d %s", &tmp->i, &tmp->s)) != EOF) ){
    if(tmp->i % 2 == 0){
      count++;
    }
    tmp++;
    }
   even=new_even = malloc((count/2)*sizeof(struct st1));
   int c = 0;
   for(int i = ( (n/2) ) ; i < n; i++){
    if(((new+i)->i )% 2 == 0){
      ((even+c)->i) = ( (new+i)-> i );
      for(int j = 0 ; j < STRSIZE ; j++){
        ( (even+c) ->s[j] ) =  ( (new+i)-> s[j] );
      }
      c++;
    }
   } 
  *size = count/2;
  return new_even;
}
