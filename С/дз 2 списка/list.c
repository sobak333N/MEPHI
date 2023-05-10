#include <stdlib.h>
#include <time.h>
#include "tittle.h"
#include <stdio.h>

int main(int ags, char *argv[]){
  node *first = NULL;
  node *second = NULL;
  node *answer = NULL;
  int r;
  FILE *fi;
  srand(time(NULL));

  while((r = rand()%100) < 90){
    first = add_head(first , r);

  }
  while((r = rand()%100) < 90){
    second = add_head(second, r);

  }

  lprint(first);
  lprint(second);
  answer = third(first , second);
  lprint(answer);

  /*head = del_head(head);
  lprint(head);


  head = add_tail(head,r);
  head = add_tail(head,rand()%100 );
  head = add_tail(head,rand()%100);
  lprint(head);
  head = add_head(head, rand()%100);
  lprint(head);

  head = sort(head);
  lprint(head);
  writefile(argv[1], head);*/
  return 0 ;
}
