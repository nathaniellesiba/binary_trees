#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
    struct binary_tree_s *parent;
} binary_tree_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL) {
        return NULL; /*Return NULL on failure*/
    }

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = parent;

    return new_node; /*Return a pointer to the new node*/
}
