#include "binary_trees.h"

typedef struct binary_tree_s heap_t
{
    int value;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
}
heap_t;

/**
* swap - Helper function to swap two values
* @a: first value
* @b: second value
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
* heapify_up - Function to maintain
* Max Heap property after insertion
* @node: element
*/
void heapify_up(heap_t *node)
{
    while (node->left != NULL || node->right != NULL)
    {
        int largest = node->value;
        heap_t *next = NULL;

        if (node->left != NULL && node->left->value > largest)
        {
            largest = node->left->value;
            next = node->left;
        }
        if (node->right != NULL && node->right->value > largest)
        {
            largest = node->right->value;
            next = node->right;
        }

        if (largest != node->value)
        {
            swap(&(node->value), &(next->value));
            node = next;
        }
        else
        {
            break;
        }
    }
}

/**
* heap_insert - Function to insert
* a value into the Max Binary Heap
* @root: topmost node with double pntr
* @value: the value
* Return: new node on success
*/
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = create_node(value);
    if (new_node == NULL)
    {
        return (NULL);  /*Return NULL on failure*/
    }

    if (*root == NULL)
    {
        *root = new_node;
        return (new_node);
    }

    heap_t *current = *root;
    while (1)
    {
        if (current->left == NULL)
        {
            current->left = new_node;
            break;
        }
        else if (current->right == NULL)
        {
            current->right = new_node;
            break;
        }
        else
        {
            if (current->left != NULL && current->right != NULL &&
                current->left->left == NULL && current->left->right == NULL &&
                current->right->left == NULL && current->right->right == NULL)
                {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }

    heapify_up(new_node);  /*Maintain Max Heap property after insertion*/
    return (new_node);
}
