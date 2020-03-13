from typing import List 

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        max_area, area = 0, 0
        while(l < r):
            if height[l] <= height[r]:
                area = height[l] * (r - l)
                l += 1
            else:
                area = height[r] * (r - l)
                r -= 1
            if area > max_area:
                max_area = area
        
        return max_area