#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap
 * @array: a pointer to the first element
 * @size: the number of elements
 * Return: a pointer to the root node
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int idx;
	heap_t *root = NULL;

	for (idx = 0; idx < size; idx++)
	{
		heap_insert(&root, array[idx]);
	}

	return (root);
}
