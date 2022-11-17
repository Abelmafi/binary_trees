#include "binary_trees.h"
/**
 * tree_height - function that measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: return 0 If tree is NULL.
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t height = 0, height_l = 0, height_r = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	height_l = 1 + tree_height(tree->left);
	height_r = 1 + tree_height(tree->right);
	height = height_l > height_r ? height_l: height_r;
	return (height);
}
/**
 * level_order - that goes through a binary tree
 * using level-order traversal.
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * @level: node pointer level.
 *
 * Return: Nothing.
 */
void level_order(const binary_tree_t *tree, void(*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	if (level > 1)
	{
		level_order(tree->left, func, level - 1);
		level_order(tree->right, func, level - 1);
	}
}
/**
 * binary_tree_levelorder - that goes through a binary tree
 * using level-order traversal.
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 *
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = tree_height(tree), i;

	if (!tree)
		return;

	for (i = 1; i <= height; i++)
		level_order(tree, func, i);
}
