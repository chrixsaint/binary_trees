#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights
 * @tree: pointer to the root node
 * Return: Height or 0
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * @heap: pointer to the root node
 * @size: address to store size
 * Return: pointer to sorted array
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int idx, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
    {
		return (NULL);
    }

	for (idx = 0; heap; idx++)
		a[idx] = heap_extract(&heap);

	return (a);
}
