#include "binary_trees.h"

/**
 * bst_insert - insert a node into a binary tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: inserted Node or NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = (bst_t *)binary_tree_node(NULL, value);
		return (*tree);
	}
	tmp = *tree;
	while (tmp)
	{
		if (tmp->n == value)
			break;
		if (tmp->n > value)
		{
			if (!tmp->left)
			{
				tmp->left = (bst_t *)binary_tree_node(tmp, value);
				return (tmp->left);
			}
			tmp = tmp->left;
		}
		if (tmp->n < value)
		{
			if (!tmp->right)
			{
				tmp->right = (bst_t *)binary_tree_node(tmp, value);
				return (tmp->right);
			}
			tmp = tmp->right;
		}
	}
	return (NULL);
}
