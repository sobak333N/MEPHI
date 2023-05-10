#include <stdlib.h>
#include <time.h>
#include "tittle.h"
#include <stdio.h>

int main(int ags, char *argv[]){
  node *head = NULL;
  int r;
  FILE *fi;
  srand(time(NULL));

  while((r = rand()%100) < 90){
    head = add_head(head , r);

  }


  lprint(head);



  head = del_head(head);
  lprint(head);


  head = add_tail(head,r);
  head = add_tail(head,rand()%100 );
  head = add_tail(head,rand()%100);
  lprint(head);
  head = add_head(head, rand()%100);
  lprint(head);

  head = sort(head);
  lprint(head);
  writefile(argv[1], head);
  return 0 ;
}
