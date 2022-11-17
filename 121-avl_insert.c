#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: a double pointer to the root node of the BST to insert the value.
 * @value:  the value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *front, *tail = NULL, *new_node;

	if (!tree || !value)
		return (NULL);
	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	front = *tree;
	while (front)
	{
		tail = front;
		if (value < front->n)
			front = front->left;
		else if (value > front->n)
			front = front->right;
		else if (value == front->n)
			return (NULL);
	}
	new_node = binary_tree_node(*tree, value);
	if (value > tail->n)
	{
		tail->right = new_node;
		new_node->parent = tail;
		return (new_node);
	}
	tail->left = new_node;
	new_node->parent = tail;
	return (new_node);
}
/**
 * avl_insert - inserts a value in an AVL Tree.
 * @tree: a double pointer to the root node of the
 * AVL tree for inserting the value.
 * @value: is the value to store in the node to be inserted.
 *
 * Return: return a pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance = 0;
	avl_t *node = bst_insert(tree, value);

	balance = binary_tree_balance(*tree);
	if (balance > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	if (balance < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));
	if (balance > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	return (node);
}
