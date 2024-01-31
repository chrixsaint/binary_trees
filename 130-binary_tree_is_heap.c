#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - goes through a binary tree
 * @tree: pointer to the root node
 * Return: 1 if all nodes are max
 **/
int check_max(const binary_tree_t *tree)
{
	int tmp1 = 1, tmp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
		{
			return (0);
		}
		tmp1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tmp2 = check_max(tree->right);
	}
	return (tmp1 && tmp2);
}
/**
 * binary_tree_is_heap - checks if heap
 * @tree: pointer to the node
 * Return: 1 in case BTS
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tp;

	if (!tree)
	{
		return (0);
	}

	tp = binary_tree_is_complete(tree);
	if (!tp)
		return (0);
	return (check_max(tree));
}
