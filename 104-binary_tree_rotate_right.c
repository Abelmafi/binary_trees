#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a left-rotation on a binary tree.
 * @tree: is a pointer to the root node of the tree to rotate.
 * Return:  a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node = NULL;

	if (!tree)
		return (NULL);
	node = tree->left;
	if (node->right)
	{
		tree->left = node->right;
		node->right->parent = tree;
	}
	else
		tree->left = NULL;
	node->parent = NULL;
	node->right = tree;
	tree->parent = node;
	return (node);
}
