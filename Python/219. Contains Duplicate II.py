from typing import List

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        record = set()
        for index, value in enumerate(nums):
            if value in record:
                return True
            record.add(value)
            if len(record) == k + 1:
                record.remove(nums[index - k])
        
        return False