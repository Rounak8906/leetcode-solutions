int largestInteger(int* nums, int numsSize, int k) {
    int count[51] = {0};

    // Check every subarray of size k
    for (int i = 0; i <= numsSize - k; i++) {

        // To make sure a number is counted only once
        // inside this subarray
        int seen[51] = {0};

        for (int j = i; j < i + k; j++) {
            seen[nums[j]] = 1;
        }

        // Count this subarray for every number present
        for (int x = 0; x <= 50; x++) {
            if (seen[x]) {
                count[x]++;
            }
        }
    }

    // Find the largest number appearing in exactly one subarray
    for (int x = 50; x >= 0; x--) {
        if (count[x] == 1) {
            return x;
        }
    }

    return -1;
}