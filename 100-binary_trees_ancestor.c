#include "binary_trees.h"
/**
 * depth - calculates depth of given node.
 * @node: a pointer to a given node.
 *
 * Return: depth value.
 */
int depth(const binary_tree_t *node)
{
	int d = 0;

	if (!node)
		return (0);
	while (node)
	{
		node = node->parent;
		d++;
	}
	return (d);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: a pointer to first node.
 * @second: a pointer to second node.
 *
 * Return: pointer to the lowest common ancestor of two given nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int depth_f = 0, depth_s = 0;
	const binary_tree_t *top, *bottom;

	if (!first || !second)
		return (NULL);

	depth_f = depth(first);
	depth_s = depth(second);
	top = (depth_f >= depth_s) ? second : first;

	while (top)
	{
		bottom = (depth_f < depth_s) ? second : first;
		while (bottom)
		{
			if (bottom == top)
				return ((binary_tree_t *)top);
			bottom = bottom->parent;
		}
		top = top->parent;
	}
	return (NULL);
}
