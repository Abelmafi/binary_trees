#include "binary_trees.h"
/**
 * bst_search - searchs for a value in binary search tree.
 * @tree: i a pointer to the root node of the bst to search.
 * @value: the value to search in the tree.
 *
 * Return: a pointer to the node containg a value equals to value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree || tree->n == value)
		return ((bst_t *)tree);

	if (tree->n < value)
		return (bst_search(tree->right, value));
	return (bst_search(tree->left, value));
}
