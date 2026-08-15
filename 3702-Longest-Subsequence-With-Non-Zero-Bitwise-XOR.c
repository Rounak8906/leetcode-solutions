int longestSubsequence(int* nums, int numsSize) {
    int x = 0;
    int hasNonZero = 0;

    for (int i = 0; i < numsSize; i++) {
        x ^= nums[i];

        if (nums[i] != 0)
            hasNonZero = 1;
    }

    if (x != 0)
        return numsSize;

    if (hasNonZero)
        return numsSize - 1;

    return 0;
}