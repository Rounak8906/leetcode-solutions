class Solution(object):
    def firstStableIndex(self, nums, k):
        n = len(nums)
        
        # suffix_min[i] stores min(nums[i..n-1])
        suffix_min = [0] * n
        suffix_min[-1] = nums[-1]
        for i in range(n - 2, -1, -1):
            suffix_min[i] = min(nums[i], suffix_min[i + 1])
        
        # Iterate from left to right to find the smallest stable index
        curr_max = float('-inf')
        for i in range(n):
            curr_max = max(curr_max, nums[i])
            if curr_max - suffix_min[i] <= k:
                return i
                
        return -1