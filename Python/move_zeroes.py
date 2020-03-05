'''
283. Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]

Note:

    1.You must do this in-place without making a copy of the array.
    2.Minimize the total number of operations.
'''
class Solution(object):

    def move_zeroes(self, nums):
        # make non zeroes elements in [0, k)
        # k is slow runner point to the place index could swap in non zero element
        # i is fast runner iterate each element and swap non zeroes ones to k if i != k
        k = 0
        for i in range(len(nums)):
            if nums[i]:
                if(i != k):
                    nums[i], nums[k] = nums[k], nums[i]
                    k += 1
                else:
                    k += 1

if __name__ == '__main__':
    nums = [1, 2, 3, 0, 4, 5, 0, 3, 11]
    Solution().move_zeroes(nums)
    print(nums)