class Solution(object):
    def uniformArray(self, nums1):
        m = min(nums1)

        if m % 2 == 1:
            return True

        for x in nums1:
            if x % 2 == 1:
                return False

        return True