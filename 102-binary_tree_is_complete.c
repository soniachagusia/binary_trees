#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int checker(const binary_tree_t *tree, size_t idx, size_t size);

/**
 * binary_tree_size -  function that measures the size of a binary tree
 * @tree:  is a pointer to the root node of the tree to measure the size
 * Return: tree is NULL, the function must return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(
				 tree->left) + binary_tree_size(tree->right));
}

/**
 * checker - function to check completeness
 * @tree: pointer to the root node
 * @idx: index of the node
 * @size: size of the tree
 * Return: 1 if true and 0 if false
 */

int checker(const binary_tree_t *tree, size_t idx, size_t size)
{
	if (tree == NULL)
		return (1);
	if (idx >= size)
		return (0);
	return (checker(tree->left, idx * 2 + 1, size) &&
		checker(tree->right, idx * 2 + 2, size));
}

/**
 * binary_tree_is_complete - func to check if binary tree is complete
 * @tree: pointer to the root node
 * Return: 0 if false and 1 if true
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t idx, size;

	if (tree == NULL)
		return (0);
	idx = 0;
	size = binary_tree_size(tree);
	return (checker(tree, idx, size));
}
