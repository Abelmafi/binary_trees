#include "binary_trees.h"
#include <stdbool.h>
/**
 * depth - this function calculates the left side depth of binary tree.
 * @root: a pointer to the root node of the tree to check.
 *
 * Return: dipth value.
 */
int depth(const binary_tree_t *root)
{
	int d = 0;

	while (root)
	{
		d++;
		root = root->left;
	}
	return (d);
}
/**
 * is_perfect - check if a binary tree is perfect binary tree.
 * @tree: a pointer to the root node of the tree to check.
 * @depth: left side depth value.
 * @level: node level.
 *
 * Return: true if the given binary tree is perfect false if its not.
 */
bool is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (!tree)
		return (true);
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);
	if (tree->left == NULL || tree->right == NULL)
		return (false);
	return (is_perfect(tree->left, depth, level + 1) &&
			is_perfect(tree->right, depth, level + 1));
}
/**
 * binary_tree_is_perfect - This function checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check.
 * Return: return 1 if its full and 0 If tree is NULL or its not full.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (!tree)
		return (0);
	d = depth(tree);
	if (is_perfect(tree, d, 0))
		return (1);
	return (0);
}
