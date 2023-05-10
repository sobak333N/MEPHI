#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define N 10
#define STRSIZE 5

struct st1{
int i;
char s[STRSIZE];
};

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

void st_rand(struct st1 *tmp, int n){
int k , j ;

srand(time(NULL));
for(k = 0 ; k < n ; k++){

(tmp+k )-> i = rand()%100;
for(j = 0 ; j < STRSIZE ; j++){
(tmp +k) -> s[j] = ((char)(65+rand()%25));
}
(tmp + k) -> s[STRSIZE] = '\0';
}
}

void st_print(struct st1 tmp[], int n){
int k;
for(k=0; k < n ; k++){
printf("%d -> [%2d][%s] \n", k , (tmp+k) -> i , (tmp+k) -> s);
}
}

int main(void){
struct st1 *pq = NULL;
pq = malloc(N*sizeof(struct st1));
if(pq == NULL){
printf("malloc: NULL \n" );
exit(2);
}

st_rand(pq , N);
st_print(pq , N);
st_sort(pq , N);

printf("\n");
st_print(pq , N);

free(pq);
pq = NULL;
return 0;

}