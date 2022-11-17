#include "binary_trees.h"
#include <stdlib.h>
/**
 * min_val_node - search min value node from tree.
 * @node:  is a pointer to the root node of the tree.
 *
 * Return: node with min value.
 */
bst_t *min_val_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
		current = current->left;
	return (current);
}
/**
 * bst_remove -  removes a node from a Binary Search Tree.
 * @root:  is a pointer to the root node of the tree
 * where you will remove a node.
 * @value: is the value to remove in the tree.
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (root);

	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			/*temp->parent = root->parent;*/
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			/*temp->parent = root->parent;*/
			free(root);
			return (temp);
		}
		temp = min_val_node(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
