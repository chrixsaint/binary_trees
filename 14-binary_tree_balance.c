#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height.
 * @tree: A pointer to the root node.
 * Return: If tree is NULL, returns nn.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lft = 0, rgt = 0;

		lft = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rgt = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((lft > rgt) ? lft : rgt);
	}
	return (0);
}
/**
 * binary_tree_balance - Measures the balance factor.
 * @tree: A pointer to the root node.
 * Return: If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}

	return (0);
}
