#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates.
 * @tree: A pointer to the root node.
 * Return: A pointer to the new root node after.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *p-pt, *tmp;

	if (tree == NULL || tree->left == NULL)
    {
		return (NULL);
    }

	p-pt = tree->left;
	tmp = p-pt->right;
	p-pt->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = p-pt;
	p-pt->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = p-pt;
		else
			tmp->right = p-pt;
	}

	return (p-pt);
}
