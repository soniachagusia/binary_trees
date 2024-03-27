#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void printer(const binary_tree_t *tree, void (*func)(int), size_t level);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 *  binary_tree_height -  function that measures the height of a binary tree
 *  @tree:  is a pointer to the root node of the tree to measure the height
 *  Return: tree is NULL, your function must return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height =  tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}
/**
 * printer - func to print the level we are
 * @tree: the root node address
 * @func: function to be called at particular nodes
 * @level: height of th node
 */

void printer(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		printer(tree->left, func, level - 1);
		printer(tree->right, func, level - 1);
	}
}
/**
 * binary_tree_levelorder - func to traverse in level order method
 * @tree: pointer to root node of the tree
 * @func: function to be called at the node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, idx = 1;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree) + 1;

	while (idx <= height)
	{
		printer(tree, func, idx);
		idx++;
	}
}
