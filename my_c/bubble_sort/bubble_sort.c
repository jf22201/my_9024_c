#include <stdio.h>
#include "bubble_sort.h"
void swap(int *pa,int *pb){
int tmp = *pa;
*pa = *pb;
*pb = tmp;
}


void bubbleSort(int *iPtr,int len){
    for(int max = len-2;max>=0;max--){
        for(int curr = 0; curr<=max;curr++){
            if (*(iPtr+curr) > *(iPtr+curr+1)){
                swap(iPtr+curr,iPtr+curr+1);
                }
        }
    }
}