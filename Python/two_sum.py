class Solution(object):
    def two_sum(self, numbers, target):
        # l is left side pointer, r is right side pointer
        # arr has been sorted
        l, r = 0, len(numbers) - 1
        while l < r :
            if numbers[l] + numbers[r] == target:
                return l+1, r + 1
            elif numbers[l] + numbers[r] < target:
                l += 1
            elif numbers[l] + numbers[r] > target:
                r -= 1
        raise ValueError('The input has no solution.')