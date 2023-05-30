#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	if (parent == NULL)
		return (NULL);

	temp = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (temp == NULL)
		return (NULL);

	temp->n = value;
	temp->parent = parent;
	temp->right = NULL;
	temp->left = parent->left;
	parent->left = temp;

	if (temp->left != NULL)
	{
		temp->left->parent = temp;
	}

	return (temp);
}
