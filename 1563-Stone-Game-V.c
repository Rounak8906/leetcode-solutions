int stoneGameV(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;

    long long prefix[501];
    int dp[501][501] = {0};

    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    for (int len = 2; len <= n; len++) {

        for (int l = 0; l + len <= n; l++) {

            int r = l + len - 1;

            /* Binary search for the split point */
            int low = l;
            int high = r - 1;

            while (low <= high) {

                int mid = (low + high) / 2;

                long long leftSum =
                    prefix[mid + 1] - prefix[l];

                long long rightSum =
                    prefix[r + 1] - prefix[mid + 1];

                if (leftSum < rightSum) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            /* Check split at high */
            if (high >= l) {
                long long leftSum =
                    prefix[high + 1] - prefix[l];

                long long rightSum =
                    prefix[r + 1] - prefix[high + 1];

                if (leftSum <= rightSum) {
                    int value = leftSum + dp[l][high];

                    if (value > dp[l][r])
                        dp[l][r] = value;
                }
            }

            /* Check split at low */
            if (low <= r - 1) {
                long long leftSum =
                    prefix[low + 1] - prefix[l];

                long long rightSum =
                    prefix[r + 1] - prefix[low + 1];

                if (leftSum <= rightSum) {
                    int value = leftSum + dp[l][low];

                    if (value > dp[l][r])
                        dp[l][r] = value;
                }

                if (rightSum <= leftSum) {
                    int value = rightSum + dp[low + 1][r];

                    if (value > dp[l][r])
                        dp[l][r] = value;
                }
            }
        }
    }

    return dp[0][n - 1];
}