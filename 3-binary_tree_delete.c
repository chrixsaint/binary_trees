#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 *
 * Description: This function deletes an entire binary tree starting
 * from the given root node. It uses a recursive approach to delete
 * each node in a post-order traversal, freeing up the memory.
 * The function sets each node's left and right pointers to NULL
 * after freeing the memory to avoid any potential dangling pointers.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
