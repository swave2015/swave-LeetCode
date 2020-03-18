from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        record = {}
        for index, num in enumerate(nums):
            complement = target - num
            if complement in record:
                return [record[complement], index]
            else:
                record[num] = index
        raise Exception('the input has no sulution')