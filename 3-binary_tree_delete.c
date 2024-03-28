#include "binary_trees.h"
#include <stdlib.h>

/**
*binary_tree_delete - takes pointer
*to the root node of the tree
*as a parameter
*@binary_tree_t: the node
*@*tree: the tree
*Return: null
*/

void binary_tree_delete(binary_tree_t *tree) 
{
    if (tree == NULL)
    {
        return (NULL);
    }
    
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
    
    free(tree);
}
