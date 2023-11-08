#include "bintree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTreeNode	*root;

	BinTree	*new = (BinTree *)malloc(sizeof(BinTree));
	if (new)
	{
		root = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		if (root)
		{
			*root = rootNode;
			root -> pLeftChild = NULL;
			root -> pRightChild = NULL;
			new -> pRootNode = root;
		}
		else
		{
			free (new);
			new = NULL;
		}
	}
	return (new);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	BinTreeNode	*ret = NULL;
	
	if (pBinTree)
		ret = pBinTree -> pRootNode;
	return (ret);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode	*node = NULL;

	if (pParentNode)
	{
		node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		if (node)
		{
			*node = element;
			node -> pLeftChild = NULL;
			node -> pRightChild = NULL;
			pParentNode -> pLeftChild = node;
		}
	}
	return (node);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode	*node = NULL;

	if (pParentNode)
	{
		node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		if (node)
		{
			*node = element;
			node -> pLeftChild = NULL;
			node -> pRightChild = NULL;
			pParentNode -> pRightChild = node;
		}
	}
	return (node);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	BinTreeNode	*node = NULL;
	
	if (pNode)
		node = pNode -> pLeftChild;
	return (node);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	BinTreeNode	*node = NULL;
	
	if (pNode)
		node = pNode -> pRightChild;
	return (node);
}

void deleteBinTree(BinTree* pBinTree)
{
	if (pBinTree)
	{
		deleteBinTreeNode(&(pBinTree -> pRootNode));
		memset(pBinTree, 0, sizeof(BinTree));
		free(pBinTree);
	}
}

void deleteBinTreeNode(BinTreeNode** pNode)
{
	if (pNode)
	{
		if (*pNode)
		{
			deleteBinTreeNode(&((*pNode) -> pLeftChild));
			deleteBinTreeNode(&((*pNode) -> pRightChild));
			memset(*pNode, 0, sizeof(BinTreeNode));
			free(*pNode);
			*pNode = NULL;
		}
	}
}

void preorderTraversalBinTree(BinTreeNode* pNode)
{
	if (pNode)
	{
		printf("data: %c\n", pNode->data);
		preorderTraversalBinTree(getLeftChildNodeBT(pNode));
		preorderTraversalBinTree(getRightChildNodeBT(pNode));
	}
}

void inorderTraversalBinTree(BinTreeNode* pNode)
{
	if (pNode)
	{
		inorderTraversalBinTree(getLeftChildNodeBT(pNode));
		printf("data: %c\n", pNode->data);
		inorderTraversalBinTree(getRightChildNodeBT(pNode));
	}
}

void postorderTraversalBinTree(BinTreeNode* pNode)
{
	if (pNode)
	{
		postorderTraversalBinTree(getLeftChildNodeBT(pNode));
		postorderTraversalBinTree(getRightChildNodeBT(pNode));
		printf("data: %c\n", pNode->data);
	}
}

BinTreeNode* getChildNodeByIndex(BinTree *pBinTree, BinTreeNode element, int index)
{
	BinTreeNode *ptr = getRootNodeBT(pBinTree);
	int i, dividend = index;
	char str[64];
	i = 0;
	while (1 < dividend)
	{
		str[i++] = dividend % 2;
		dividend /= 2;
	}
	while (1 < i--)
	{
		if (str[i])
			ptr = getRightChildNodeBT(ptr);
		else
			ptr = getLeftChildNodeBT(ptr);
	}
	if (str[0])
		ptr = insertRightChildNodeBT(ptr, element);
	else
		ptr = insertLeftChildNodeBT(ptr, element);
	return (ptr);
}
