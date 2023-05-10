#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"

int main(int argc, char *argv[]) {
    Tree *root = NULL;
    char *s;

    s = malloc(128);
    memset(s, 0, 128);

    if (argv[1] != NULL)
        strcpy(s, argv[1]);
    else
        return -1;

    root = create(*s++);

    while (*s)
        root = add(root, *s++);

    showtree(root, 0);
    delete(search(root, 'D'));
    showtree(root, 0);

    return 0;
}

