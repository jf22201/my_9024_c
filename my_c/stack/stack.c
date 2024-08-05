#include <stdio.h>
#include <stdlib.h>
#include "stack.h"




StackPtr createStack(){
    StackPtr pStack = (StackPtr) malloc(sizeof(struct Stack));
    pStack->numItems = 0;
    return pStack;

}

STACK_ITEM_TYPE peekStack(StackPtr pStack){
    return pStack->LLHeadNodePtr->value;
}

void pushStack(StackPtr pStack, STACK_ITEM_TYPE value){
    StackNodePtr newNodePtr = (StackNodePtr) malloc(sizeof(struct StackNode));
    newNodePtr->value = value;
    if (pStack->numItems<1){
        pStack->LLHeadNodePtr = newNodePtr;
        pStack->numItems++;
    }else{
    newNodePtr->nextNode = pStack->LLHeadNodePtr;
    pStack->LLHeadNodePtr = newNodePtr;
    pStack->numItems++;
    }
}

STACK_ITEM_TYPE popStack(StackPtr pStack){
    StackNodePtr removeNodePtr = pStack->LLHeadNodePtr;
    STACK_ITEM_TYPE ret_val = removeNodePtr->value;
    pStack->LLHeadNodePtr = pStack->LLHeadNodePtr->nextNode;
    removeNodePtr->nextNode = NULL;
    free(removeNodePtr);
    pStack->numItems--;
    return ret_val;

}

int isStackEmpty(StackPtr pStack){
    return pStack->numItems<=0;
}