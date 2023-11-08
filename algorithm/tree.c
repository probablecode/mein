#include <stdio.h>
#include <stdlib.h>
typedef struct s_node t_node;
typedef struct s_node
{
	int		val;
	t_node	*lc;
	t_node	*rc;
}t_node;

typedef	struct s_tree
{
	t_node	*root;
	int		level;
}t_tree;

t_node	*new_node(int value)
{
	t_node	*new;
	new = (t_node *)malloc(sizeof(t_node));
	new -> val = value;
	new -> lc = NULL;
	new -> rc = NULL;
}

t_tree	*create_tree(void)
{
	t_tree	*tree;

	tree = (t_tree *)malloc(sizeof(t_tree));
	tree -> root = NULL;
	tree -> level = 0;
	return (tree);
}

void	insert_node(t_tree *tree, t_node *node)
{
	t_node	*tmp;

	if (!(tree -> root))
	{
		tree -> root = node;
		tree -> level = 1;
		return ();
	}
	(if 2^n - 1이면)
	tmp = tree -> root;
	node -> lc = tmp;
	tree -> root = node;
	level++;
}


t_tree	*make_level(t_tree	*tree, int lv)
{
	tree -> root
	tree -> level = 1;


	while (tree -> level < lv)
	{

		(tree -> level)++;
	}
}



t_tree	*enlarge_tree(t_tree	*tree)
{
	t_tree	*copy;
	int		lv;

	lv = tree -> level;
	copy = create_tree();
	for (int i = 0; i < level; i++)
	{
		
	}

	free(copy);
	return (tree);
}


// if (next (tree -> root, &a))
int	next(t_node	*r, t_node **addr)
{
		t_node	*r;
		
		if ()
}


void	delete_node(t_node *node)
{

}
void	delete_tree(t_tree	*tree)
{
	
}

int	empty_leaf(t_node *parent, t_node **addr)
{


	//Ah Shit,
}


int	main(void)
{
	t_tree	*tree;
	
	tree = create_tree();
	return (0);
}
