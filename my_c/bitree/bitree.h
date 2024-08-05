#ifndef BITREE_H
#define BITREE_H

struct BiTree{
   struct BiTreeNode *root;
};
typedef struct BiTree* BiTreePtr;


struct BiTreeNode{
    int value;
    struct BiTreeNode* LChild;
    struct BiTreeNode* RChild;
};

void preorderTrav(struct BiTreeNode *pNode);
struct BiTree* createBiTree();
struct BiTreeNode* createNode(int value,struct BiTreeNode* lChild, struct BiTreeNode* rChild);
void postorderTrav(struct BiTreeNode *pNode);
void inorderTrav(struct BiTreeNode *pNode);
void insertBST(struct BiTreeNode** root,int value);
struct BiTreeNode* searchBST(struct BiTreeNode* root, int value);
int deleteBST(struct BiTreeNode** pNodePtr,int value);
struct BiTreeNode* getMinValueNode(struct BiTreeNode* pNode);
#endif