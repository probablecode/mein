#include "binsearchtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
BinSearchTree	*createBinSearchTree()
{
	BinSearchTree	*new;

	new = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (new)
		new -> pRootNode = NULL;
	return (new);
}

BinSearchTreeNode	*searchBST(BinSearchTree *pBinSearchTree, int key)
{
	BinSearchTreeNode	*ret = NULL;
	int	cmp;

	if (pBinSearchTree)
	{
		ret = pBinSearchTree -> pRootNode;
		while (ret)
		{
			cmp = ret -> key;
			if (key == cmp)
				break;
			else if (key < cmp)
				ret = ret -> pLeftChild;
			else
				ret = ret -> pRightChild;
		}
	}
	return (ret);
}

int	getParentNode(BinSearchTreeNode *pCurrentNode, int key, BinSearchTreeNode **ppResult)
{
	BinSearchTreeNode	*parent = NULL;
	int	cmp;

	while (pCurrentNode)
	{
		cmp = pCurrentNode -> key;
		if (key == cmp)
		{
			printf("Error, repeated key - [%d], getParentNode()\n", key);
			return (FALSE);
		}
		parent = pCurrentNode;
		else if (key < cmp)
			pCurrentNode = pCurrentNode -> pLeftChild;
		else
			pCurrentNode = pCurrentNode -> pRightChild;
	}
	*ppResult = parent;
	return (TRUE);
}

BinSearchTreeNode	*createNewBinSearchTreeNode(int key, char value)
{
	BinSearchTreeNode	*node;

	node = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (node)
	{
		node -> key = key;
		node -> value = value;
		node -> pLeftChild = NULL;
		node -> pRightChild = NULL;
	}
	return (node);
}

void	insertNewBinSearchTreeNode(BinSearchTree *pBinSearchTree, BinSearchTreeNode * pParentNode, BinSearchTreeNode *pNewNode)
{
	if (pBinSearchTree)
	{
		if (pParentNode)
		{
			if (pNewNode -> key < pParentNode -> key)
				pParentNode -> pLeftChild = pNewNode;
			else
				pParentNode -> pRightChild = pNewNode;
		}
		else
			pBinSearchTree -> pRootNode = pNewNode;
	}
}
int	insertDataBST(BinSearchTree *pBinSearchTree, int key, char value)
{
	BinSearchTreeNode	*parent;
	BinSearchTreeNode	*new;
	int	ret = FALSE;

	if (pBinSearchTree)
	{
		if (getParentNode(pBinSearchTree -> pRootNode, key, &parent))
		{
			new = createNewBinSearchTreeNode(key, value);
			if (new)
			{
				insertNewBinSearchTreeNode(pBinSearchTree, parent, new);
				ret = TRUE;
			}
		}
	}
	return (ret);
}

BinSearchTreeNode	*searchWithParentNodeBST(BinSearchTree *pBinSearchTree, int key, BinSearchTreeNode **ppParentNode);

void deleteNodeNoChild(BinSearchTree *pBinSearchTree, BinSearchTreeNode *pParentNode, BinSearchTreeNode *pDelNode);
void deleteNodeOneChild(BinSearchTree *pBinSearchTree, BinSearchTreeNode *pParentNode, BinSearchTreeNode *pDelNode);
void deleteNodeTwoChildren(BinSearchTree *pBinSearchTree, BinSearchTreeNode *pParentNode, BinSearchTreeNode *pDelNode);
int	deleteDataBST(BinSearchTree *pBinSearchTree, int key);
void	deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode);
void	deleteBinSearchTree(BinSearchTree *pBinSearchTree);
void	displayBinSearchTree(BinSearchTreeNode *pTreeNode, int level, char type);
