#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Element;

int cmpVal(const void* a, const void* b) {
    return ((Element*)a)->val - ((Element*)b)->val;
}

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    
    // Pair each value with its original index
    Element* elements = (Element*)malloc(sizeof(Element) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        elements[i].val = nums[i];
        elements[i].idx = i;
    }
    
    // Sort all elements by value
    qsort(elements, numsSize, sizeof(Element), cmpVal);
    
    int* groupIndices = (int*)malloc(sizeof(int) * numsSize);
    int left = 0;
    
    while (left < numsSize) {
        int right = left;
        // Extend group as long as the adjacent difference is <= limit
        while (right + 1 < numsSize && elements[right + 1].val - elements[right].val <= limit) {
            right++;
        }
        
        int groupSize = right - left + 1;
        
        // Collect the original indices for this group
        for (int i = 0; i < groupSize; i++) {
            groupIndices[i] = elements[left + i].idx;
        }
        
        // Sort indices to place smallest values at the leftmost available spots
        qsort(groupIndices, groupSize, sizeof(int), cmpInt);
        
        for (int i = 0; i < groupSize; i++) {
            result[groupIndices[i]] = elements[left + i].val;
        }
        
        left = right + 1;
    }
    
    free(elements);
    free(groupIndices);
    return result;
}