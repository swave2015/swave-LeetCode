from typing import List

class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if k < 1 or t < 0:
            return False
        # reference
        # https://www.hrwhisper.me/leetcode-contains-duplicate-i-ii-iii/
        # divide the nums into bucket by num // t, 
        # the nums in same bucket all meet the condation abs(nums[i] - nums[j]) <= t,
        # and the two nums in neighboring bucket nums // t - 1 and nums // t + 1
        # may satisfy the condation abs(nums[i] - nums[j]) <= t
        buckets = {}
        for i, num in enumerate(nums):
            # t may be 0
            key = num // max(1, t)
            for b in (buckets.get(key - 1), buckets.get(key), buckets.get(key + 1)):
                if b is not None and abs(b - num) <= t:
                    return True
                
            # make sure the number of elements in buckets dict no more than k.
            # when the number of elements up to k, the next num in nums is k + 1
            # so the length of sliding window remains <= k
            # there're no identical keys in buckets, because when two keys are identical
            # means the abs difference between the two nums no more than t, and 
            # the program will return in previous.
            if len(buckets) == k:
                buckets.pop(nums[i - k] // t)
            buckets[key] = num
        
        return False
    
'''
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        if k <= 0 or t < 0: return False
        key_to_val = {}
        for i, num in enumerate(nums):
            key = num // (t + 1)
            
            # if key in key_to_val then meet nums[i] - nums[j] <= t
            # because in when nums[i] and nums[j] in same bucket
            # the num range in same bucket is [key_to_val * (t + 1), (key_to_val + 1) * (t + 1)
            # so the diff range in same bucket is [0, t + 1), otherwise num type is integer
            # the diff between them can't be decimal like t + 0.3, eventuall the diff range is
            # [0, t] satify the condition nums[i] - nums[j] <= t when they in same bucket
            
            if key in key_to_val \
                    or key + 1 in key_to_val and key_to_val[key + 1] - num <= t \
                    or key - 1 in key_to_val and num - key_to_val[key - 1] <= t:
                return True
            if i >=k:
                del key_to_val[nums[i-k] // (t + 1)]
            key_to_val[key] = num
        return False
'''