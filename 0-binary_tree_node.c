#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: pointer to the new node, or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	temp = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	temp->n = value;
	temp->parent = parent;
	temp->left = NULL;
	temp->right = NULL;

	return (temp);
}
