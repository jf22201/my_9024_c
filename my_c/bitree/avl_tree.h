#include "bitree.h"
#ifndef AVL_TREE_H
#define AVL_TREE_H
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct AVLTreeNode* AVLTreeNodePtr;
typedef struct AVLTree* AVLTreePtr;

struct AVLTreeNode{
    int value;
    AVLTreeNodePtr LChild;
    AVLTreeNodePtr RChild;
    int balanceFactor;
};

struct AVLTree{
    AVLTreeNodePtr root;
};
int getHeight(AVLTreeNodePtr pNode);
AVLTreePtr createAVLTree();
AVLTreeNodePtr createAVLNode(int value,AVLTreeNodePtr lChild, AVLTreeNodePtr rChild);
void insertAVL(AVLTreeNodePtr* pNodePtr,int value);
void printBST(AVLTreeNodePtr root);
void deleteAVL(AVLTreeNodePtr* pNodePtr,int value);




#endif