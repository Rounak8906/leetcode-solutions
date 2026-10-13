
class Solution(object):
    def maxAlternatingSum(self, nums):
        nums.sort(key=abs)

        n = len(nums)
        k = (n + 1) // 2

        ans = 0

        for i in range(n):
            if i < k:
                ans += nums[n - 1 - i] ** 2
            else:
                ans -= nums[n - 1 - i] ** 2

        return ans
