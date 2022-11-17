#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_delete - this function deletes an entire binary tree.
 * @tree: a pointer to the root node of the tree to delete.
 * Return: Nothing.
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
