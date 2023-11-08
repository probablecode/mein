#include "bintree.h"
#include <stdio.h>

int main() 
{
	//char *data = "BCDEFGHIJKLM";
    BinTreeNode node;
    BinTree *tree;

    node.data = 'A';
    tree = makeBinTree(node);
	for (int i = 2; i < 16; i++)
	{
		if (i != 11 && i != 12)
		{
			node.data++;
			getChildNodeByIndex(tree, node, i);
		}
	}

/*
	BinTreeNode *left = insertLeftChildNodeBT(getRootNodeBT(tree), (BinTreeNode){'B'});
    BinTreeNode *left_left = insertLeftChildNodeBT(left, (BinTreeNode){'D'});
    BinTreeNode *left_right = insertRightChildNodeBT(left, (BinTreeNode){'E'});
    BinTreeNode *left_right_left = insertLeftChildNodeBT(left_right, (BinTreeNode){'J'});
    BinTreeNode *left_left_left = insertLeftChildNodeBT(left_left, (BinTreeNode){'H'});
    BinTreeNode *left_left_right = insertRightChildNodeBT(left_left, (BinTreeNode){'I'});
    BinTreeNode *right = insertRightChildNodeBT(getRootNodeBT(tree), (BinTreeNode){'C'});
    BinTreeNode *right_left = insertLeftChildNodeBT(right, (BinTreeNode){'F'});
    BinTreeNode *right_left_right = insertRightChildNodeBT(right_left, (BinTreeNode){'K'});
    BinTreeNode *right_right = insertRightChildNodeBT(right, (BinTreeNode){'G'});
    BinTreeNode *right_right_left = insertLeftChildNodeBT(right_right, (BinTreeNode){'L'});
    BinTreeNode *right_right_right = insertRightChildNodeBT(right_right, (BinTreeNode){'M'}); 
*/
    printf("===Preorder===\n");
    preorderTraversalBinTree(getRootNodeBT(tree));
    printf("===Inorder===\n");
    inorderTraversalBinTree(getRootNodeBT(tree));
    printf("===Postorder===\n");
    postorderTraversalBinTree(getRootNodeBT(tree));

    deleteBinTree(tree);
	return (0);
}
