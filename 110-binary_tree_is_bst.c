#include "binary_trees.h"
#include <limits.h>
/**
 * is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @node: is a pointer to the root node of the tree to check.
 * @min: min value.
 * @max: max value.
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst(const binary_tree_t *node, int min, int max)
{
	if (!node)
		return (1);
	if (node->n < min || node->n > max)
		return (0);
	return (is_bst(node->left, min, node->n - 1) &&
			is_bst(node->right, node->n + 1, max));
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: is a pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (is_bst(tree, INT_MIN, INT_MAX))
		return (1);
	return (0);
}
