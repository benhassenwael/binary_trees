#include "binary_trees.h"


/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: root of tree to measure
 *
 * Return: integer height of tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
        int left_height, right_height;

        if (!tree)
                return (0);
        if (tree->left == NULL && tree->right == NULL)
                return (0);
        left_height = binary_tree_height(tree->left);
        right_height = binary_tree_height(tree->right);

        if (left_height > right_height)
                return (left_height + 1);
        else
                return (right_height + 1);
}

/**
 *
 */
void traverse_level(const binary_tree_t *tree, int lvl, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (lvl == 0)
		func(tree->n);
	else if (lvl > 0)
	{
		traverse_level(tree->left, lvl - 1, func);
		traverse_level(tree->right, lvl - 1, func);
	}
}

/**
 * binary_tree_levelorder - level-order binary tree traversal
 * @tree: root of tree to traverse
 * @func: function to call on values of visited nodes
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, i;

	height = binary_tree_height(tree);
	for (i = 0; i <= height; i++)
		traverse_level(tree, i, func);
}
