#include "binary_trees.h"
/**
 * array_to_bst - turns an array into a bst
 * @array: pointer to array
 * @size: size of array
 * Return: BST or NULL
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (array && size)
	{
		for (i = 0; i < size; i++)
			bst_insert(&root, array[i]);
	}
	return (root);
}
