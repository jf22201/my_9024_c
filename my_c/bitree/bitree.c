#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

int getHeight(AVLTreeNodePtr pNode){
    if(!pNode){
        return 0;
    }
    else{
        return 1+max(getHeight(pNode->LChild),getHeight(pNode->RChild));
    }
}

AVLTreePtr createAVLTree(){
    return (AVLTreePtr)(sizeof(struct AVLTree));
}

AVLTreeNodePtr createNode(int value,AVLTreeNodePtr lChild, AVLTreeNodePtr rChild){
    AVLTreeNodePtr pNode = (AVLTreeNodePtr) malloc(sizeof(struct BiTreeNode));
    pNode->value = value;
    pNode->LChild = lChild;
    pNode->RChild = rChild;
    return pNode;
}


void insertAVL(AVLTreeNodePtr* pNodePtr,int value){
    AVLTreeNodePtr newNode = createNode(value,NULL,NULL);
    AVLTreeNodePtr pNode = *pNodePtr;
    if(!pNode){
        *pNodePtr = newNode;
    }else{
        if(value<pNode->value){
            insertAVL(&(pNode->LChild),value);
            updateBalanceFactor(pNode);
        }else if(value>pNode->value){
            insertAVL(&(pNode->RChild),value);
            updateBalanceFactor(pNode);
        }
        else{
            return;
        }
    }
    //if imbalanced do rotations
    if(pNode->balanceFactor>1 || pNode->balanceFactor<-1){
        balanceRotations(pNodePtr);
    }
}

void updateBalanceFactor(AVLTreeNodePtr pNode){
    int lHeight = getHeight(pNode->LChild);
    int rHeight = getHeight(pNode->RChild);
    int bfactor = lHeight-rHeight;
    pNode->balanceFactor = bfactor;
}

void balanceRotations(AVLTreeNodePtr* pNodePtr){
    AVLTreeNodePtr pNode = *pNodePtr;
    if(pNode->balanceFactor>1){
        //check the bf of the left child
        updateBalanceFactor(pNode->LChild);
        if(pNode->LChild->balanceFactor == -1){
            //LR case
            leftRotate(&(pNode->LChild));
            rightRotate(pNodePtr);
        }else{
            //LL rotation
            rightRotate(pNodePtr);

        }

    }else{ //balancefactor is
    //check the bf of the right
    updateBalanceFactor(pNode->RChild);
    if(pNode->RChild==1){
        //RL rotation
        rightRotate(&(pNode->LChild));
        leftRotate(pNodePtr);
    }
    else{
        //RR rotation
        leftRotate(pNodePtr);
    }

    }




}

void leftRotate(AVLTreeNodePtr* pNodePtr){
    AVLTreeNodePtr pNode = *pNodePtr;
    AVLTreeNodePtr pNodeC = pNode;
    AVLTreeNodePtr pNodeA = pNodeC->RChild;
    AVLTreeNodePtr pNodeB = pNodeA->LChild;
    pNodeA->LChild = pNodeC;
    pNodeC->RChild = pNodeB;
    *pNodePtr = pNodeA;
}

void rightRotate(AVLTreeNodePtr* pNodePtr){
    AVLTreeNodePtr pNode = *pNodePtr;
    AVLTreeNodePtr pNodeC = pNode;
    AVLTreeNodePtr pNodeA = pNodeC->LChild;
    AVLTreeNodePtr pNodeB = pNodeA->RChild;
    pNodeA->RChild = pNodeC;
    pNodeC->LChild = pNodeB;
}

