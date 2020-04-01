#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }
        int c = sum / 2;
        vector<bool> memo;
        for (int i = 0; i <= c; i++) {
            memo.push_back(nums[0] == i ? true : false);
        }
        for (int i = 1; i < nums.size(); i++) {
            if (memo[c]) {
                return true;
            }
            for (int j = c; j >= nums[i]; j--) {
                memo[j] = memo[j] || memo[j - nums[i]];
            }
        }

        return memo[c];
    }
};