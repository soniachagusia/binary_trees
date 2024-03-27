#include "binary_trees.h"
int binry_tree_height(const binary_tree_t *tree);
int bin_tree_count_nodes(const binary_tree_t *tree);

/**
*binry_tree_height - calculates height of binary (sub)tree by traversing it's
*  branches
*@tree: pointer to node whose (sub)tree is to be traversed
*Return: max path(height)
*/

int binry_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = binry_tree_height(tree->left);
	right_height = binry_tree_height(tree->right);

	return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
*bin_tree_count_nodes - counts nodes on a (sub)tree
*@tree: pointer to node whose (sub)tree is to be traversed
*Return: number of nodes
*/

int bin_tree_count_nodes(const binary_tree_t *tree)
{
	int left_count, right_count;

	if (tree == NULL)
		return (0);

	left_count = bin_tree_count_nodes(tree->left);
	right_count = bin_tree_count_nodes(tree->right);

	return (1 + left_count + right_count);
}


/**
*binary_tree_is_perfect - checks if a binary tree is perfect
*@tree: pointer to the root node of the tree to check
*Return: 1 if tree is perfect, 0 if not
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, node_count;

	if (tree == NULL)
		return (0);

	height = binry_tree_height(tree);
	node_count = bin_tree_count_nodes(tree);

	return ((1 << (height + 1)) - 1  == node_count);
}
