#include "binary_trees.h"

/**
 * binary_trees_ancestor -  function that finds the lowest common ancestor
 * @first: is a pointer to the first node
 * @second:  is a pointer to the second node
 * Return: Your function must return a pointer to the lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *a, *b;

	if (first == NULL || second == NULL)
		return (NULL);

	a = first;
	while (a)
	{
		b = second;
		while (b)
		{
			if (a == b)
				return ((binary_tree_t *)a);
			b = b->parent;
		}
		a = a->parent;
	}
	return (NULL);
}
