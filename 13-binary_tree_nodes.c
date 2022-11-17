#include "binary_trees.h"
/**
 * binary_tree_nodes - This function counts the nodes
 * which at least 1 child in a binary tree.
 * @tree: a pointer to the root node of the tree to count the number of leaves.
 * Return: return number of nodes and 0 If tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);

	nodes = ((tree->left || tree->right) ?
		1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right) :
			binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
	return (nodes);
}
