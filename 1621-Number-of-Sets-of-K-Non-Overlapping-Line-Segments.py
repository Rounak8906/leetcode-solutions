class Solution(object):
    def numberOfSets(self, n, k):
        MOD = 10**9 + 7

        dp = [[0] * (k + 1) for _ in range(n)]
        
        for i in range(n):
            dp[i][0] = 1

        for i in range(1, n):
            for j in range(1, k + 1):
                dp[i][j] = dp[i - 1][j]
                
                if i >= 1:
                    dp[i][j] += dp[i - 1][j - 1] * i
                
                dp[i][j] %= MOD

        return dp[n - 1][k]