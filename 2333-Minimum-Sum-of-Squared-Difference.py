
class Solution(object):
    def minSumSquareDiff(self, nums1, nums2, k1, k2):
        diff = [abs(a - b) for a, b in zip(nums1, nums2)]
        k = k1 + k2

        if sum(diff) <= k:
            return 0

        left = 0
        right = max(diff)

        while left < right:
            mid = (left + right) // 2
            need = sum(max(0, x - mid) for x in diff)

            if need <= k:
                right = mid
            else:
                left = mid + 1

        level = left
        need = sum(max(0, x - level) for x in diff)
        remaining = k - need

        ans = 0
        for x in diff:
            x = min(x, level)

            if x == level and remaining > 0:
                x -= 1
                remaining -= 1

            ans += x * x

        return ans
