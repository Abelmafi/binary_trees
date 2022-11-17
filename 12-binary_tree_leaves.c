#include "binary_trees.h"
/**
 * binary_tree_leaves - This function counts the leaves in a binary tree.
 * @tree: a pointer to the root node of the tree to count the number of leaves.
 * Return: return number of leaves and 0 If tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (0);

	leaves = ((!tree->left && !tree->right) ? 1 +
			binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right) :
			binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
	return (leaves);

}
