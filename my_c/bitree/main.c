#include <stdio.h>
#include "avl_tree.h"


void main(){
    AVLTreePtr myTree = createAVLTree();
    insertAVL(&(myTree->root),30);
    insertAVL(&(myTree->root),20);
    insertAVL(&(myTree->root),40);
    insertAVL(&(myTree->root),10);
    deleteAVL(&(myTree->root),40);

   
    
}