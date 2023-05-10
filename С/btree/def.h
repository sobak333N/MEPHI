typedef struct tree {
    unsigned char key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} Tree;

Tree *create(unsigned char key);
Tree *add(Tree *root, unsigned char key);
Tree *search(Tree *root, unsigned char key);
Tree *min(Tree *root);
void delete(Tree *del);
void showtree(Tree *root, int p);