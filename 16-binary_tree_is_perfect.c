#include "binary_trees.h"

/**
 * depth - measure the depth of a binary tree
 * @node: root of the binary tree
 *
 * Return: integer depth of the tree
 */
int depth(const binary_tree_t *node)
{
	int d = 0;

	while (node != NULL)
	{
		d++;
		node = node->left;
	}
	return (d);
}

/**
 * is_perfect - check whether binary tree is perfect
 * @root: tree to check
 * @d: depth of the tree
 * @level: level of the current node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect(const binary_tree_t *root, int d, int level)
{
	if (root == NULL)
		return (0);

	if (root->left == NULL && root->right == NULL)
		return (d == level + 1);

	if (root->left == NULL || root->right == NULL)
		return (0);

	return (is_perfect(root->left, d, level + 1) &&
	       is_perfect(root->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - check whether binary tree is perfect
 * @tree: tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = depth(tree);

	return (is_perfect(tree, d, 0));
}
