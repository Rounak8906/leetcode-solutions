
class Solution(object):
    def minSumSquareDiff(self, nums1, nums2, k1, k2):
        diff = [abs(a - b) for a, b in zip(nums1, nums2)]
        k = k1 + k2

        if sum(diff) <= k:
            return 0

        diff.sort(reverse=True)

        while k > 0:
            diff[0] -= 1
            diff.sort(reverse=True)
            k -= 1

        return sum(x * x for x in diff)
