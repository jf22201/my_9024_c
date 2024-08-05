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
        //left imbalance

    }else
    //right imbalance


}

void 