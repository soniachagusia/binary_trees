#include "binary_trees.h"

/**
 * bst_search - func that searches for values in bst
 * @tree: pointer to the root node
 * @value: the value being searched
 * Return: pointer to node with value being serched
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));

		return (bst_search(tree->right, value));
	}

	return (NULL);
}
