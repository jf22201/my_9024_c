#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getHeight(AVLTreeNodePtr pNode){
    if(!pNode){
        return 0;
    }
    else{
        return 1+MAX(getHeight(pNode->LChild),getHeight(pNode->RChild));
    }
}

AVLTreePtr createAVLTree(){
    return (AVLTreePtr)malloc((sizeof(struct AVLTree)));
}

AVLTreeNodePtr createAVLNode(int value,AVLTreeNodePtr lChild, AVLTreeNodePtr rChild){
    AVLTreeNodePtr pNode = (AVLTreeNodePtr) malloc(sizeof(struct AVLTreeNode));
    pNode->value = value;
    pNode->LChild = lChild;
    pNode->RChild = rChild;
    return pNode;
}
void updateBalanceFactor(AVLTreeNodePtr pNode){
    int lHeight;
    int rHeight;
    if(pNode->LChild){
        lHeight = getHeight(pNode->LChild);
    }else{
        lHeight = 0;
    }
    if(pNode->RChild){
        rHeight = getHeight(pNode->RChild);
    }else{
        rHeight = 0;
    }
    int bfactor = lHeight-rHeight;
    pNode->balanceFactor = bfactor;
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
    *pNodePtr = pNodeA;
}

AVLTreeNodePtr getSmallestRightSuccessor(AVLTreeNodePtr pNode){
    AVLTreeNodePtr currNode = pNode;
    while(currNode->LChild != NULL){
        currNode = pNode->LChild;
    }
    return currNode;
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
    if(pNode->RChild->balanceFactor==1){
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



void insertAVL(AVLTreeNodePtr* pNodePtr,int value){
    AVLTreeNodePtr pNode;
    if(*pNodePtr==NULL){
        AVLTreeNodePtr newNode = createAVLNode(value,NULL,NULL);
        *pNodePtr = newNode;
        pNode = *pNodePtr;
        }else{
        pNode = *pNodePtr;
        if(value<pNode->value){
            insertAVL(&(pNode->LChild),value);
        }else if(value>pNode->value){
            insertAVL(&(pNode->RChild),value);
        }
        else{
            return;
        }
    }
    updateBalanceFactor(pNode);
    //if imbalanced do rotations
    if(pNode->balanceFactor>1 || pNode->balanceFactor<-1){
        balanceRotations(pNodePtr);
    }
}


void deleteAVL(AVLTreeNodePtr* pNodePtr,int value){
    AVLTreeNodePtr pNode;
    if(*pNodePtr == NULL){
        return;
    }
    pNode =*pNodePtr;
    
    if(pNode->value == value){
        if(pNode->LChild == NULL){
            *pNodePtr = pNode->RChild;
            free(pNode);
        }else if(pNode->RChild == NULL){
            *pNodePtr = pNode->LChild;
            free(pNode);
        }else{
            //both children have Nodes
            //get smallest right successor then swap values
            AVLTreeNodePtr pSuccessor = getSmallestRightSuccessor(pNode);
            int tmp = pNode->value;
            pNode->value = pSuccessor->value;
            pSuccessor->value = tmp;
            deleteAVL(&(pNode->RChild),value);
            }
    }else{
        //yet to find node, recursively call delete on the children
        if(value<pNode->value){
            deleteAVL(&(pNode->LChild),value);
        }
        else{
            deleteAVL(&(pNode->RChild),value);
        }
        updateBalanceFactor(pNode);
    }
    if(pNode->balanceFactor>1 || pNode->balanceFactor<-1){
        //if imbalanced do rotations
        balanceRotations(pNodePtr);
    }
}

// void deleteAVL(AVLTreeNodePtr* pNodePtr,int value){
//     continue;
// }
void printBST(AVLTreeNodePtr root) {
    if (root != NULL) {
        printBST(root->LChild);
        printf("%d ", root->value);
        printBST(root->RChild);
    }
}







