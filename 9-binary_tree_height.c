#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: return 0 If tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, height_l = 0, height_r = 0;

	if (!tree)
		return (0);
	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	height = height_l > height_r ? height_l + 1 : height_r + 1;
	return (height);
}
