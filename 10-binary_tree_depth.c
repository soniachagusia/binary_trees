#include "binary_trees.h"

/**
 *  binary_tree_depth -  function that measures the depth of a node
 *  @tree: is a pointer to the node to measure the depth
 *  Return: tree is NULL, your function must return 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth);
}
