#include "ft_btree.h"

void					btree_rotate_left(btree **root)
{
	btree				*tmp;

	tmp = (*root)->left;
	(*root)->left = (*root)->left->right;
	tmp->right = *root;
	*root = tmp;
}

void					btree_rotate_right(btree **root)
{
	btree				*tmp;

	tmp = (*root)->right;
	(*root)->right = (*root)->right->left;
	tmp->left = *root;
	*root = tmp;
}
