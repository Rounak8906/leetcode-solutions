#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
    // Allocate memory for arr1, arr2, and the final result
    int* arr1 = (int*)malloc(numsSize * sizeof(int));
    int* arr2 = (int*)malloc(numsSize * sizeof(int));
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    int size1 = 0;
    int size2 = 0;
    
    // Initial distribution
    arr1[size1++] = nums[0];
    arr2[size2++] = nums[1];
    
    // Distribute remaining elements based on the last elements
    for (int i = 2; i < numsSize; i++) {
        if (arr1[size1 - 1] > arr2[size2 - 1]) {
            arr1[size1++] = nums[i];
        } else {
            arr2[size2++] = nums[i];
        }
    }
    
    // Concatenate arr1 and arr2 into result
    int k = 0;
    for (int i = 0; i < size1; i++) {
        result[k++] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        result[k++] = arr2[i];
    }
    
    // Free temporary arrays
    free(arr1);
    free(arr2);
    
    return result;
}