#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the lvs.
 * @tree: A pointer to the root node.
 * Return: The number of lvs found
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lvs = 0;

	if (tree)
	{
		lvs += (!tree->left && !tree->right) ? 1 : 0;
		lvs += binary_tree_leaves(tree->left);
		lvs += binary_tree_leaves(tree->right);
	}
	return (lvs);
}
