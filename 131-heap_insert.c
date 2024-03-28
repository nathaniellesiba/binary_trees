#include "binary_trees.h"

typedef struct heap_s
{
    int value;
    struct heap_s *left;
    struct heap_s *right;
} heap_t;

/**
* swap - Helper function to swap two values
* @a: pointer to the first value
* @b: pointer to the second value
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
* @node: pointer to the current node
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
* @root: double pointer to the root node
* @value: the value to be inserted
* Return: pointer to the new node on success, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = malloc(sizeof(heap_t));
    if (new_node == NULL)
    {
        return NULL;  // Return NULL on failure
    }

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL)
    {
        *root = new_node;
        return new_node;
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
            if (current->left->left == NULL || current->left->right == NULL)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }

    heapify_up(new_node);  // Maintain Max Heap property after insertion
    return new_node;
}
