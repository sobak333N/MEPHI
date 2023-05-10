#define STRSIZE 5
#define N 13


typedef struct st1{
  int i;
  char s[STRSIZE+1];
} st1_t;
void file_w( char *file , struct st1 *st, int n);
void st_rand(struct st1 *tmp , int n);
void st_print(struct st1 tmp[], int n);
st1_t *st_rand1(int n);
void st_sort(struct st1 *tmp, int n);
void file_a( char *file , struct st1 *st, int n);
struct st1 *file_r(char *file, int *size);
