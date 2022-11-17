#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: is a pointer to the root node of the tree to rotate.
 * Return:  a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node = NULL;

	if (!tree)
		return (NULL);
	node = tree->right;
	if (node->left)
	{
		tree->right = node->left;
		node->left->parent = tree;
	}
	else
		tree->right = NULL;
	node->parent = NULL;
	node->left = tree;
	tree->parent = node;
	return (node);
}
