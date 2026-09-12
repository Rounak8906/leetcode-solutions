class Solution(object):
    def maximumWeight(self, intervals):
        n = len(intervals)

        # Add original index
        a = []
        for i in range(n):
            a.append([intervals[i][0], intervals[i][1], intervals[i][2], i])

        # Sort by ending position
        a.sort(key=lambda x: x[1])

        ends = [x[1] for x in a]

        # dp[i][k] = best answer using first i intervals and k intervals
        dp = [[(0, ()) for _ in range(5)] for _ in range(n + 1)]

        import bisect

        for i in range(1, n + 1):
            l, r, w, index = a[i - 1]

            for k in range(5):
                # Don't choose current interval
                dp[i][k] = dp[i - 1][k]

                if k > 0:
                    # Find last interval whose end < current start
                    p = bisect.bisect_left(ends, l, 0, i - 1)

                    old_score, old_indices = dp[p][k - 1]

                    new_score = old_score + w
                    new_indices = tuple(sorted(old_indices + (index,)))

                    if new_score > dp[i][k][0]:
                        dp[i][k] = (new_score, new_indices)
                    elif new_score == dp[i][k][0]:
                        if new_indices < dp[i][k][1]:
                            dp[i][k] = (new_score, new_indices)

        # We can choose at most 4 intervals
        best = (0, ())

        for k in range(5):
            if dp[n][k][0] > best[0]:
                best = dp[n][k]
            elif dp[n][k][0] == best[0] and dp[n][k][1] < best[1]:
                best = dp[n][k]

        return list(best[1])