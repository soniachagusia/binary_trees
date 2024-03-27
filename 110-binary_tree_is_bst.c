#include "binary_trees.h"
#include "limits.h"

int binary_tree_is_bst(const binary_tree_t *tree);
int bst_helper(const binary_tree_t *tree, int low, int high);

/**
 * binary_tree_is_bst - func that checks if tree is a valid bst
 * @tree: pointer to the root node to be validated
 * Return: 1 if true and 0 if false
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * bst_helper - func to validate if tree is bst
 * @tree: pointer to the root node
 * @low: value smallest node visited
 * @high: value of largest node visited too far
 * Return: 1 if true and 0 if not
 */
int bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);

		return (bst_helper(tree->left, low, tree->n - 1) &&
			bst_helper(tree->right, tree->n + 1, high));
	}

	return (1);
}
