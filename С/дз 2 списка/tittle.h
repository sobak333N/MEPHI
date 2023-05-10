#define N 40

typedef struct Node{
  long int data;
  struct Node *prev;
  struct Node *next;
  char s[N];
} node;


void lprint(node *head);
node *add_head(node *head, int hh);
node *add_tail(node *head, int hh, node *first);
node *del_head(node *head);
node *del_tail(node *head);

int llength(node *head);
node *sort(node *head);
void writefile(const char *path, node *head);
node *third( node *first , node *second);