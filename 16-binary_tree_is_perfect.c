#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of the binary tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: the depth of a node in the binary tree
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_tree_get_node_level - gets the level of a node
 * @tree: pointer to the node to get its level
 * Return: level of the node
*/
size_t binary_tree_get_node_level(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (1 + binary_tree_get_node_level(tree->parent));
}

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect 0r 0 if not perfect
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t l = binary_tree_height(tree->left);
	size_t r = binary_tree_height(tree->right);
	size_t node_d = binary_tree_depth(tree);
	size_t level = binary_tree_get_node_level(tree);

	if (l != r)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (node_d == level);

	if (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right))
		return (1);
	return (0);
}
