#include "binary_trees.h"
/**
 * height_of - calculate height of given binary tree.
 * @node: a pointer to the root node of the tree to measure the height.
 * Return: height of tree.
 */
int height_of(binary_tree_t *node)
{
	int left_side, right_side;

	if (!node)
		return (0);
	left_side = height_of(node->left);
	right_side = height_of(node->right);
	if (left_side > right_side)
		return (left_side + 1);
	return (right_side + 1);
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
	size_t height = height_of(tree), i;

	if (!tree)
		return;

	for (i = 1; i <= height; i++)
		level_order(tree, func, i);
}
