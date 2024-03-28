#include "binary_trees.h"

typedef struct binary_tree_s {
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} heap_t;

/**
* heap_insert - Function to insert a value into the Max Binary Heap
* @root: pointer to the root node
* @value: the value to be inserted
* Return: pointer to the new node on success, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = (heap_t *)malloc(sizeof(heap_t));
    if (!new_node) 
    {
        return NULL;  // Return NULL on failure
    }

    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL)
    {
        *root = new_node;
        return new_node;
    }

    if (value <= (*root)->n)
    {
        new_node->left = *root;
        *root = new_node;
    }
    else
    {
        heap_t *current = *root;
        while (current->left != NULL && current->right != NULL)
        {
            if (value <= current->left->n)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        if (current->left == NULL)
        {
            current->left = new_node;
        }
        else
        {
            current->right = new_node;
        }
    }

    return new_node;
}
