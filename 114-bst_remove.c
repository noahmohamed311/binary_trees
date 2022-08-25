#include "binary_trees.h"

/**
 * bst_min - finds the smallest node from a bst
 * @root: a pointer to the root node of the tree
 * Return: a pointer to the smallest node
 */
bst_t *bst_min(bst_t *root)
{
	bst_t *tmp = root;

	while (tmp->left)
		tmp = tmp->left;

	return (tmp);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 * Return: A pointer to the new root node
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *minNode = NULL;

	/* No children or right-child only */
	if (!node->left)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (!parent ? node->right : root);
	}

	/* Left-child only */
	if (!node->right)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (!parent ? node->left : root);
	}
	/* Two children */
	minNode = bst_min(node->right);
	node->n = minNode->n;

	return (bst_delete(root, minNode));
}

/**
 * bst_remove_recursive - Removes a node from a bst
 * @root: a pointer to the root node of the tree where you will remove a node
 * @node: A pointer to the current node in the bst.
 * @value: The value to remove from the bst.
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - removes a node from a bst
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node or NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
