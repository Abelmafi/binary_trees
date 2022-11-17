#include "binary_trees.h"
#include <stdbool.h>
#include <stdlib.h>
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
 * is_avl - checks if a binary tree is a valid.
 * @node: a pointer to the root node of the avl to check.
 *
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
bool is_avl(const binary_tree_t *node)
{
	int h_l, h_r;

	if (!node)
		return (true);
	h_l = height_of(node->left);
	h_r = height_of(node->right);
	if (abs(h_l - h_r) <= 1 && is_avl(node->left) && is_avl(node->right))
		return (true);
	return (false);
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree.
 * @tree: a pointer to the root node of the avl to check.
 *
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
 *
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (is_avl(tree))
		return (1);
	return (0);
}
