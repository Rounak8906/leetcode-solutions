long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long countMultiples(int* coins, int n, long long x) {
    long long count = 0;

    // Check every subset of coins
    for (int mask = 1; mask < (1 << n); mask++) {

        long long multiple = 1;
        int bits = 0;
        int valid = 1;

        for (int i = 0; i < n; i++) {

            if (mask & (1 << i)) {
                bits++;

                long long g = gcd(multiple, coins[i]);

                // Avoid overflow
                if (multiple > x / (coins[i] / g)) {
                    valid = 0;
                    break;
                }

                multiple = multiple / g * coins[i];
            }
        }

        if (!valid || multiple > x)
            continue;

        // Inclusion-exclusion
        if (bits % 2 == 1)
            count += x / multiple;
        else
            count -= x / multiple;
    }

    return count;
}

long long findKthSmallest(int* coins, int coinsSize, int k) {

    long long left = 1;
    long long right = (long long)coins[0] * k;

    // Find a safe upper bound
    for (int i = 1; i < coinsSize; i++) {
        long long value = (long long)coins[i] * k;

        if (value < right)
            right = value;
    }

    // Binary search
    while (left < right) {

        long long mid = left + (right - left) / 2;

        long long count = countMultiples(coins, coinsSize, mid);

        if (count >= k)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}