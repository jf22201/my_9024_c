#ifndef STACK_H
#define STACK_H
struct StackNode{
    STACK_ITEM_TYPE value;
    StackNodePtr nextNode;
    };
struct Stack{
    int numItems;
    StackNodePtr LLHeadNodePtr;
};
typedef long STACK_ITEM_TYPE;
struct Stack;
typedef struct StackNode *StackNodePtr;
typedef struct Stack *StackPtr;
STACK_ITEM_TYPE peekStack(StackPtr pStack);
StackPtr createStack();
void pushStack(StackPtr pStack, STACK_ITEM_TYPE value);
STACK_ITEM_TYPE popStack(StackPtr pStack);
#endif
