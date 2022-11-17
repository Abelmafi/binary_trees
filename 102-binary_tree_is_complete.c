#include "binary_trees.h"
#include <stdbool.h>
/**
 * countNumNodes - Count the number of nodes
 * @root: a pointer to root node of the tree.
 * Return: number of node.
 */
int countNumNodes(const binary_tree_t *root)
{
	if (!root)
		return (0);
	return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}
/**
 * is_complete - checks if a binary tree is complete using recursive function.
 * @tree:  is a pointer to the root node of the tree to check.
 * @index: tree nodes level index.
 * @num_nodes: total number of tree nodes.
 *
 * Return: true if the tree is complete and false if its not.
 */
bool is_complete(const binary_tree_t *tree, int index, int num_nodes)
{
	if (!tree)
		return (true);
	if (index >= num_nodes)
		return (false);
	return (is_complete(tree->left, 2 * index + 1, num_nodes) &&
		is_complete(tree->right, 2 * index + 2, num_nodes));
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree:  is a pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete and 0 if its not.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int num_nodes;

	if (!tree)
		return (0);
	num_nodes = countNumNodes(tree);
	if (is_complete(tree, 0, num_nodes))
		return (1);
	return (0);
}
