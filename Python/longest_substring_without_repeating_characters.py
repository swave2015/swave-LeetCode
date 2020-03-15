class Solution:
    # 3. Longest Substring Without Repeating Characters
    def lengthOfLongestSubstring(self, s: str) -> int:
        dicts = {}
        res = 0
        start = 0
        for i, value in enumerate(s):
            if value in dicts:
                start = max(start, dicts[value] + 1)
            res = max(res, i - start + 1)
            dicts[value] = i
        
        return res