#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int getMaxLength(vector<int>& nums, int index) {
        if (memo[index] != -1) {
            return memo[index];
        }
        int res = 1;
        for (int i = 0; i <= index - 1; i++) {
            if (nums[i] < nums[index])
                res = max(res, getMaxLength(nums, i) + 1);
        }
        memo[index] = res;
        return res;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        memo = vector<int>(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++)
            res = max(res, getMaxLength(nums, i));

        return res;
    }
};