#define MPRT 255
#define SIZE 80

typedef struct tree {
    unsigned char key;
    float value;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} Tree;

typedef struct llist{
    char* lec;
    struct llist *next;
} LList;


LList *lnew(void);
LList *ladd(LList *list , char *s);
LList *makellist(char *s);
int exprlen(LList *expr);
LList *lecs(LList *list , int i);
void printllist(LList *expr);
int lenllist(LList *head);


Tree *create(unsigned char key);
Tree *add(Tree *root, unsigned char key);
Tree *search(Tree *root, unsigned char key);
Tree *min(Tree *root);
Tree *maketree(char expr[], int first , int last);
void delete(Tree *del);
void showtree(Tree *root, int p);
int lastop(char expr[], int first , int last);
unsigned char priority(char c);
Tree *tnew(void);
Tree *leaf(char c);
int calculate(Tree *root);
int power(int first, int second);
void printTree(Tree *root, int h);