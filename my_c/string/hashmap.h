#ifndef HASHMAP_H
#define HASHMAP_H
#define START_BUCKET_COUNT 2
#define LOAD_FACTOR_THRESHOLD 0.75

typedef int HashKeyType;
typedef char* HashValueType;
typedef struct BucketEntry* BucketEntryPtr;
typedef struct HashMap* HashMapPtr;
struct BucketEntry{
    HashKeyType key;
    HashValueType value;
    BucketEntryPtr next;
};

struct HashMap{
int bucketArrSize;
BucketEntryPtr* BucketsArray;
int numBucketsStored;
};



#endif