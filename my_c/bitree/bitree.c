#include <stdio.h>
#include "bitree.h"
#include <stdlib.h>

struct BiTree* createBiTree(){
    struct BiTree* pTree = (struct BiTree*) malloc(sizeof(struct BiTree));
    
}

void insertBST(struct BiTreeNode** root,int value){
    struct BiTreeNode* newNode = createNode(value,NULL,NULL);
    struct BiTreeNode* pNode = *root;
    if(!pNode){
        *root = newNode;
    }else{
        if(value<pNode->value){
            insertBST(&(pNode->LChild),value);
        }else if(value>pNode->value){
            insertBST(&(pNode->RChild),value);
        }
        else{
            return;
        }
    }
    
}

struct BiTreeNode* searchBST(struct BiTreeNode* root, int value){
    if(value>root->value){
        if(!root->LChild){
            return NULL;
        }
        searchBST(root->LChild,value);
    }else if(value<root->value){
        if(!root->RChild){
            return NULL;
        }
        searchBST(root->RChild,value);
    }
    else{
        struct BiTreeNode* root;
    }
}

int deleteBST(struct BiTreeNode** pNodePtr,int value){
    struct BiTreeNode* pNode = *pNodePtr;
    if(pNode){
        //check that pNode exists
        if(value< pNode->value){
            return deleteBST(&(pNode->LChild),value);
        }else if(value>pNode->value){
            return deleteBST(&(pNode->RChild),value);
        }
        if(pNode->LChild == NULL){
            //handles no children or RChild only
            struct BiTreeNode* tmp = pNode->RChild;
            free(pNode);
            *pNodePtr = tmp;
        }else if(pNode->RChild == NULL){
            struct BiTreeNode* tmp = pNode->LChild;
            free(pNode);
            *pNodePtr = tmp;
        }else{
            //both are not null
            struct BiTreeNode* minNode = getMinValueNode(pNode->RChild);
            int tmp_val = pNode->value;
            pNode->value = minNode->value;
            minNode->value = tmp_val;
            return deleteBST(&(pNode->RChild),value);

        }
    }

}

struct BiTreeNode* getMinValueNode(struct BiTreeNode* pNode){
    while(pNode->LChild){
        pNode = pNode->LChild;
    }
    return pNode;
}

void insertBiTree(struct BiTree *pTree,int value){
    if(!pTree->root){
       struct BiTreeNode* pNode = createNode(value,NULL,NULL);
        pTree->root = pNode;
    }
    
}

struct BiTreeNode* createNode(int value,struct BiTreeNode* lChild, struct BiTreeNode* rChild){
struct BiTreeNode* pNode = (struct BiTreeNode*) malloc(sizeof(struct BiTreeNode));
pNode->value = value;
pNode->LChild = lChild;
pNode->RChild = rChild;
return pNode;
}

void preorderTrav(struct BiTreeNode *pNode){
if(pNode){
printf("visiting %d \n",pNode->value);
preorderTrav(pNode->LChild);
preorderTrav(pNode->RChild);
}
}


void postorderTrav(struct BiTreeNode *pNode){
    if(pNode){

postorderTrav(pNode->LChild);
postorderTrav(pNode->RChild);
printf("visiting %d \n",pNode->value);
}
}

void inorderTrav(struct BiTreeNode *pNode){
if(pNode){
    inorderTrav(pNode->LChild);
    printf("visiting %d \n",pNode->value);
    inorderTrav(pNode->RChild);
}
}
