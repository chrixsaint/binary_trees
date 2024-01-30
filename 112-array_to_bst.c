#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree
 * @array: A pointer to the first element.
 * @size: The number of items in the array.
 * Return: A pointer to the root node.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t idx, xdx;

	if (array == NULL)
    {
		return (NULL);
    }

	for (idx = 0; idx < size; idx++)
	{
		for (xdx = 0; xdx < idx; xdx++)
		{
			if (array[xdx] == array[idx])
				break;
		}
		if (xdx == idx)
		{
			if (bst_insert(&tree, array[idx]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
