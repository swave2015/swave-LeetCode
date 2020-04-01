#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<int>> memo;

    bool tryPartition(vector<int> &nums, int index, int sum) {
        if (sum == 0) {
            return true;
        }
        if (index < 0 || sum < 0) {
            return false;
        }
        if (memo[index][sum] != -1) {
            return memo[index][sum] == 1;
        }
        memo[index][sum] = (tryPartition(nums, index - 1, sum) ||
                            tryPartition(nums, index - 1, sum - nums[index])) ? 1 : 0;

        return memo[index][sum] == 1;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1, -1));
        bool res = tryPartition(nums, nums.size() - 1, sum / 2);
        return res;
    }
};
