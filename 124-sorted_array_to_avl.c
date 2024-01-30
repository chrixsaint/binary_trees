#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left
 * Return: no returns
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t midpt;

	if (size == 0)
		return;

	midpt = (size / 2);
	midpt = (size % 2 == 0) ? midpt - 1 : midpt;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[midpt]);
		create_tree(&((*node)->left), array, midpt, 1);
		create_tree(&((*node)->left), array + midpt + 1, (size - 1 - midpt), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[midpt]);
		create_tree(&((*node)->right), array, midpt, 1);
		create_tree(&((*node)->right), array + midpt + 1, (size - 1 - midpt), 2);
	}
}

/**
 * sorted_array_to_avl - creates root node and calls
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t midpt;

	root = NULL;

	if (size == 0)
    {
		return (NULL);
    }

	midpt = (size / 2);

	midpt = (size % 2 == 0) ? midpt - 1 : midpt;

	root = binary_tree_node(root, array[midpt]);

	create_tree(&root, array, midpt, 1);
	create_tree(&root, array + midpt + 1, (size - 1 - midpt), 2);

	return (root);
}
