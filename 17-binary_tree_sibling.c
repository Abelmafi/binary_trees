#include "binary_trees.h"
/**
 * binary_tree_sibling - function that finds the sibling of a node.
 * @node: a pointer to the root node of the tree to check.
 * Return: a pointer to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
