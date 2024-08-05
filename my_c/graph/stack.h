#ifndef STACK_H
#define STACK_H
typedef int STACK_ITEM_TYPE;
struct Stack;
typedef struct StackNode *StackNodePtr;
typedef struct Stack *StackPtr;
STACK_ITEM_TYPE peekStack(StackPtr pStack);
StackPtr createStack();
void pushStack(StackPtr pStack, STACK_ITEM_TYPE value);
STACK_ITEM_TYPE popStack(StackPtr pStack);
int isStackEmpty(StackPtr pStack);
int isOnStack(StackPtr pStack,STACK_ITEM_TYPE value);
struct StackNode{
    STACK_ITEM_TYPE value;
    StackNodePtr nextNode;
    };
struct Stack{
    int numItems;
    StackNodePtr LLHeadNodePtr;
};

#endif

