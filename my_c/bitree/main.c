#include <stdio.h>
#include "avl_tree.h";


void main(){
    AVLTreePtr myTree = createAVLTree();
    insertAVL(&(myTree->root),30);
    insertAVL(&(myTree->root),20);
    insertAVL(&(myTree->root),10);
    
}