#include "binary_trees.h"

/**
*binary_tree_node - takes pointr to parent
*@binary_tree_t - the tree node
*
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	I[Inew_node->parent = parent;

    return (new_node);
}
