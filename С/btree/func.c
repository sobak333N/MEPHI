#include <stdio.h>
#include <stdlib.h>
//#include <error.h>
#include <string.h>
#include "def.h"

Tree *create(unsigned char key) {
    Tree *tmp;
    if ((tmp = malloc(sizeof(Tree))) == NULL) {
        perror("malloc: ");
        exit(1);
    }
    tmp->key = key;
    tmp->parent = NULL;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

Tree *add(Tree *root, unsigned char key) {
    Tree *rtmp = root;
    Tree *rsave = NULL;
    Tree *tmp;
    if ((tmp = malloc(sizeof(Tree))) == NULL) {
        perror("malloc: ");
        exit(1);
    }
    tmp->key = key;
    while (rtmp != NULL) {
        rsave = rtmp;
        if (key < rtmp->key)
            rtmp = rtmp->left;
        else
            rtmp = rtmp->right;
    }
    tmp->parent = rsave;
    tmp->left = NULL;
    tmp->right = NULL;
    if (key < rsave->key)
        rsave->left = tmp;
    else
        rsave->right = tmp;
    return root;
}

Tree *search(Tree *root, unsigned char key) {
    if ((root == NULL) || (root->key == key))
        return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

Tree *min(Tree *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

void delete(Tree *del) {
    Tree *tmp;
    if (del == NULL)
        return;
    if ((del->left == NULL) && (del->right == NULL)) {
        if (del == del->parent->right)
            del->parent->right = NULL;
        else
            del->parent->left = NULL;
        free(del);
        return;
    }
    if ((del->left == NULL) && (del->right != NULL)) {
        if (del == del->parent->right) {
            del->parent->right = del->right;
            del->parent->right->parent = del->parent;
        } else {
            del->parent->left = del->right;
            del->parent->left->parent = del->parent;
        }
        free(del);
        return;
    }
    if ((del->left != NULL) && (del->right == NULL)) {
        if (del == del->parent->right) {
            del->parent->right = del->left;
            del->parent->right->parent = del->parent;
        } else {
            del->parent->left = del->left;
            del->parent->left->parent = del->parent;
        }
        free(del);
        return;
    }
    if ((del->left != NULL) && (del->right != NULL)) {
        tmp = min(del->right);
        del->key = tmp->key;
        delete(tmp);
    }
}

void showtree(Tree *root, int p) {
    int i;
    if (root == NULL)
        return;
    p += 5;
    showtree(root->right, p);
    printf("\n");
    for (i = 5; i < p; i++)
        printf(" ");
    printf("%c\n", root->key);
    showtree(root->left, p);
}

