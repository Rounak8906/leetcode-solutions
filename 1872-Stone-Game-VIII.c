int stoneGameVIII(int* stones, int stonesSize) {
    // 1. Calculate prefix sums in-place
    for (int i = 1; i < stonesSize; i++) {
        stones[i] += stones[i - 1];
    }

    // 2. Base case: picking all stones at index n - 1
    int dp = stones[stonesSize - 1];

    // 3. Backward transition: dp[i] = max(dp[i + 1], prefix_sum[i] - dp[i + 1])
    for (int i = stonesSize - 2; i >= 1; i--) {
        if (stones[i] - dp > dp) {
            dp = stones[i] - dp;
        }
    }

    return dp;
}