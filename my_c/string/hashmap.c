#include <stdio.h>
#include "hashmap.h"

HashMapPtr createHashMap(){
    HashMapPtr newHashMap = (HashMapPtr) malloc(sizeof(struct HashMap));
    newHashMap->bucketArrSize = START_BUCKET_COUNT;
    newHashMap->numBucketsStored = 0;
    newHashMap->BucketsArray = (BucketEntryPtr) malloc(sizeof(struct BucketEntry)*newHashMap->bucketArrSize);
}

BucketEntryPtr createBucket(HashKeyType key,HashValueType value){
    BucketEntryPtr newBucket = (BucketEntryPtr)malloc(sizeof(struct BucketEntry));
    newBucket->key = key;
    newBucket->value = value;
}

int GetHash(char* key){
    int sum = 0;
    for(int i = 0; key[i]!='\0';i++){
        sum = sum + key[i];
    }
    return sum;
}

long getLoadFactor(HashMapPtr pMap){
    return ((long)pMap->numBucketsStored)/((long)pMap->bucketArrSize);
}

void hashMapInsert(HashMapPtr pMap,HashKeyType key, HashValueType value){
    int insertIndex = GetHash(key) % pMap->bucketArrSize;
    BucketEntryPtr newBucket = createBucket(key,value);
    if(pMap->BucketsArray[insertIndex] == NULL){
        pMap->BucketsArray = newBucket;
    }
    else{
        BucketEntryPtr currBucket = pMap->BucketsArray[insertIndex];
        while(currBucket->next != NULL){
            currBucket = currBucket->next;
        }
        currBucket->next = newBucket;
    }

}

HashValueType hashMapGet(HashMapPtr pMap,HashKeyType key){
    int index = GetHash(key) % pMap->bucketArrSize;
    if(pMap->BucketsArray[index] == NULL){
        return NULL;
    }
    else{
        BucketEntryPtr currBucket = pMap->BucketsArray[index];
        while(currBucket->next != NULL){
            if(currBucket->key == key){
                return currBucket->value;
            }
            currBucket = currBucket->next;
        }
        return NULL;
    }
}

void hashMapDelete(HashMapPtr pMap,HashKeyType key){
    int index = GetHash(key) % pMap->bucketArrSize;
    if (pMap->BucketsArray[index] == NULL){
        
    }
    
}

