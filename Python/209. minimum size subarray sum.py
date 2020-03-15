from typing import List

class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        # define a sliding window to contain sub array 
        # sliding window range is [l, ..., r]
        l, r = 0, -1
        sum = 0
        res = len(nums) + 1
        while l < len(nums):
            if r + 1 < len(nums) and sum < s:
                r += 1
                sum += nums[r]
            else:
                sum -= nums[l]
                l += 1
            # l >= len(nums) only happens when the siliding windows is empty
            # and sum == 0， as s > 0, not meet sum >= s, so r - l + 1 == 0 
            # won't happen
            if sum >= s:
                res = min(res, r - l + 1)
        if res == len(nums) + 1:
            return 0
        return res