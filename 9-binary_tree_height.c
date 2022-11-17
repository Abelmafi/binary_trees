#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: return 0 If tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	height_l = 1 + binary_tree_height(tree->left);
	height_r = 1 + binary_tree_height(tree->right);
	if (height_l > height_r)
	       	return (height_l);
	return (height_r);
}
