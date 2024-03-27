#include "binary_trees.h"

/**
 * array_to_bst - func that builds bst from array
 * @array: pointer to the first array converted
 * @size: number of elements in the array
 * Return: pointer to to root of created bst
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t ind, idx;

	if (array == NULL)
		return (NULL);

	for (ind = 0; ind < size; ind++)
	{
		for (idx = 0; idx < ind; idx++)
		{
			if (array[idx] == array[ind])
				break;
		}
		if (idx == ind)
		{
			if (bst_insert(&tree, array[ind]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
