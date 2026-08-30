int minimumDeletions(int* nums, int numsSize) {
    int minIndex = 0;
    int maxIndex = 0;

    // Find positions of minimum and maximum
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[minIndex]) {
            minIndex = i;
        }

        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }

    // Make left the smaller index and right the larger index
    int left = minIndex < maxIndex ? minIndex : maxIndex;
    int right = minIndex > maxIndex ? minIndex : maxIndex;

    // Three possible strategies
    int removeFront = right + 1;
    int removeBack = numsSize - left;
    int removeBoth = (left + 1) + (numsSize - right);

    // Return minimum
    int answer = removeFront;

    if (removeBack < answer) {
        answer = removeBack;
    }

    if (removeBoth < answer) {
        answer = removeBoth;
    }

    return answer;
}