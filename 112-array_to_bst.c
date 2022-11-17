#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array.
 * @array: array of values to be inserted.
 * @size: array size.
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
