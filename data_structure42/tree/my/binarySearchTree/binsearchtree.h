#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

typedef struct BinSearchTreeNodeType
{
	int	key;
	char value;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
} BinSearchTreeNode;

typedef struct BinSearchTreeType
{
	BinSearchTreeNode* pRootNode;
} BinSearchTree;

BinSearchTree	*createBinSearchTree();
BinSearchTreeNode	*searchBST(BinSearchTree *pBinSearchTree, int key);
int	getParentNode(BinSearchTreeNode *pCurrentNode, int key, BinSearchTreeNode **ppResult);
BinSearchTreeNode	*createNewBinSearchTreeNode(int key, char value);
void	insertNewBinSearchTreeNode(BinSearchTree *pBinSearchTree, BinSearchTreeNode * pParentNode, BinSearchTreeNode *pNewNode);
int	insertDataBST(BinSearchTree *pBinSearchTree, int key, char value);
BinSearchTreeNode	*searchWithParentNodeBST(BinSearchTree *pBinSearchTree, int key, BinSearchTreeNode **ppParentNode);
void deleteNodeNoChild(BinSearchTree *pBinSearchTree, BinSearchTreeNode *pParentNode, BinSearchTreeNode *pDelNode);
void deleteNodeOneChild(BinSearchTree *pBinSearchTree, BinSearchTreeNode *pParentNode, BinSearchTreeNode *pDelNode);
void deleteNodeTwoChildren(BinSearchTree *pBinSearchTree, BinSearchTreeNode *pParentNode, BinSearchTreeNode *pDelNode);
int	deleteDataBST(BinSearchTree *pBinSearchTree, int key);
void	deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode);
void	deleteBinSearchTree(BinSearchTree *pBinSearchTree);
void	displayBinSearchTree(BinSearchTreeNode *pTreeNode, int level, char type);
#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
