#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor
 * @first: Pointer to the first
 * @second: Pointer to the second.
 * Return: null If no common ancestors.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mom, *pop;

	if (!first || !second)
    {
		return (NULL);
    }
	if (first == second)
    {
		return ((binary_tree_t *)first);
    }

	mom = first->parent, pop = second->parent;
	if (first == pop || !mom || (!mom->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mom == second || !pop || (!pop->parent && mom))
    {
		return (binary_trees_ancestor(mom, second));
    }
	return (binary_trees_ancestor(mom, pop));
}
