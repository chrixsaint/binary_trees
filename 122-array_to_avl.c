#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree
 * @array: A pointer to the first element
 * @size: The number of elements.
 * Return: A pointer to the root node of the created AVL.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t idx, xdx;

	if (array == NULL)
		return (NULL);

	for (idx = 0; idx < size; idx++)
	{
		for (xdx = 0; xdx < idx; xdx++)
		{
			if (array[xdx] == array[idx])
			{
				break;
			}
		}
		if (xdx == idx)
		{
			if (avl_insert(&tree, array[idx]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
