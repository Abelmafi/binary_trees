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
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 * Return: balance factor of given tree or 0 If tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (height_of(tree->left) - height_of(tree->right));
}
