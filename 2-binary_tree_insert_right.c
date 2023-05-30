#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the
 * right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the created node,
 * or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	if (parent == NULL)
		return (NULL);

	temp = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (temp == NULL)
		return (NULL);

	temp->n = value;
	temp->parent = parent;
	temp->left = NULL;
	temp->right = parent->right;
	parent->right = temp;

	if (temp->right != NULL)
	{
		temp->right->parent = temp;
	}

	return (temp);
}
