from typing import List

class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        res = 0
        for i, point_i in enumerate(points):
            record = {}
            for j, point_j in enumerate(points):
                if i != j:
                    dis = self.__dis(point_i, point_j)
                   
                    if dis in record:
                        record[dis] += 1
                    else:
                        record[dis] = 1
            for _, count in record.items():
                if count >= 2:
                    res += count * (count - 1)
                
        return res
    
    def __dis(self, point_a, point_b):
        return pow((point_a[0] - point_b[0]), 2) + pow((point_a[1] - point_b[1]), 2)