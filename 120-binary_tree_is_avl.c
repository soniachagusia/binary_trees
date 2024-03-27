#include "binary_trees.h"
#include "limits.h"

int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
size_t height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - func that checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if true and 0 if false
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - func that checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * @lo: value of the smallest node visited thus far
 * @hi: value of the largest node visited this far
 * Return: 1 if true and 0 if false
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lt_ht, rt_ht, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lt_ht = height(tree->left);
		rt_ht = height(tree->right);
		diff = lt_ht > rt_ht ? lt_ht - rt_ht : rt_ht - lt_ht;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: If tree is NULL, func must return 0, else return height
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
