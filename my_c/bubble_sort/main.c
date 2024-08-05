#include <stdio.h>
#include "bubble_sort.h"
void main(){
    int arr[] = {5,3,10,16,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,len);
    for(int i=0;i<len;i++){
        printf("%d\n",arr[i]);
    }

}