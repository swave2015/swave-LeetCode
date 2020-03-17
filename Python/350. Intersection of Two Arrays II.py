from typing import List

class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        record = {}
        for i in nums1:
            if i not in record:
                record[i] = 1
            else:
                record[i] += 1
        res = []
        for i in nums2:
            if i in record and record[i] > 0:
                res.append(i);
                record[i] -= 1
                if record[i] == 0:
                    # record.pop(i)
                    del record[i]
        return res