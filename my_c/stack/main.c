#include <stdio.h>
#include "stack.h"

void main(){
    StackPtr myStackPtr = createStack();
    pushStack(myStackPtr,6);
    printf("popping %ld\n",popStack(myStackPtr));
    pushStack(myStackPtr,10);
    pushStack(myStackPtr,15);
    printf("popping %ld\n",popStack(myStackPtr));
    pushStack(myStackPtr,20);
    printf("popping %ld\n",popStack(myStackPtr));
    printf("popping %ld\n",popStack(myStackPtr));

    

}
