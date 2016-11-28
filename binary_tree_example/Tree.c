#include "Tree.h"

void			destroy_tree(struct node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		free(leaf);
	}
}

void			insert_in_tree(int key, struct node **leaf)
{
	if (*leaf == NULL)
	{
		*leaf = (struct node*) malloc(sizeof(struct node));
		(*leaf)->key = key;
	
		(*leaf)->left = NULL;
		(*leaf)->right = NULL;

		printf("Binary tree successfully created.\n");
	}
	else if (key < (*leaf)->key)
		insert_in_tree(key, &(*leaf)->left);
	else if (key > (*leaf)->key)
		insert_in_tree(key, &(*leaf)->right);
}

struct node		*search(int key, struct node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key)
			return leaf;
		else if (key != leaf->key)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else
		return 0;
}

int				main(void)
{
	struct node *binaryTree = NULL;

	insert_in_tree(5, &binaryTree);	
	printf("Search node which contains 5: FOUND %p\n", search(5, binaryTree));
	destroy_tree(binaryTree);
	printf("Tree destroyed.\n");

	return EXIT_SUCCESS;
}
