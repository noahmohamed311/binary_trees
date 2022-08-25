#include "binary_trees.h"

/**
 * get_max - check if all values in the tree are greater than a value
 * @tree: pointer to the root node of the tree to check
 * @val: value to check
 *
 * Return: 1 if true else false
 */
int get_max(const binary_tree_t *tree, int val)
{
	int l, r;

	if (tree == NULL)
		return (1);
	if (tree->n > val)
	{
		l = get_max(tree->left, val);
		r = get_max(tree->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

/**
 * get_min - check if all values in the tree are less than a specific value
 * @tree: pointer to the root node of the tree to check
 * @val: value to check
 *
 * Return: 1 if true else false
 */
int get_min(const binary_tree_t *tree, int val)
{
	int l, r;

	if (tree == NULL)
		return (1);
	if (tree->n < val)
	{
		l = get_min(tree->left, val);
		r = get_min(tree->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (get_min(tree->left, tree->n) && get_max(tree->right, tree->n))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
				return (1);
		}

	}
	return (0);
}
