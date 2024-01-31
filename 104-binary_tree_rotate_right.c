#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates.
 * @tree: A pointer to the root node.
 * Return: A pointer to the new root node after.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *ppt, *tmp;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}

	ppt = tree->left;
	tmp = ppt->right;
	ppt->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = ppt;
	ppt->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = ppt;
		else
			tmp->right = ppt;
	}

	return (ppt);
}
