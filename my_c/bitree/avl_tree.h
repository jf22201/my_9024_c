#include "bitree.h"
#ifndef AVL_TREE_H
#define AVL_TREE_H

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





#endif