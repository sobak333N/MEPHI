#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "func.h"
#define N 13

int main(int argc, char *argv[]){
  FILE *fi, * fo;
  struct st1 *pq1=NULL, *pq2=NULL;
  int stn,rdn;
  if(argc < 3){printf("a.out <src> <dst> \n"); exit(1);}
  printf("input: ");
  scanf("%d", &stn);
  pq1 = st_rand1(stn);
  file_w(argv[1], pq1, stn);
  st_sort(pq1, stn);
  file_a(argv[1], pq1, stn);

  pq2 = file_r(argv[1], &rdn);
  st_print(pq1, stn);
  printf("\n");
  st_print(pq2, rdn);
  file_w(argv[2], pq2, rdn);
  return 0;
}
