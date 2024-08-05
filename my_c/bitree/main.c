#include <stdio.h>
#include "bitree.h"


void main(){
    int nums[] = {50, 20, 10, 30, 40, 70, 60, 100, 90, 80};
    //create tree
    struct BiTree* myTree = createBiTree();
   for(int i=0;i<sizeof(nums)/sizeof(nums[0]);i++){
    
    insertBST(&(myTree->root),nums[i]);

   }
   
   for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {                        
        deleteBST(&(myTree->root),nums[i]);
   }
    
}