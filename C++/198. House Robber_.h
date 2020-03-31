#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        if (nums.size() <= 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        for (int i = 2; i < nums.size(); i++) {
            memo[i] = max(memo[i] + memo[i - 2], memo[i - 1]);
        }

        return memo[nums.size() - 1];
    }
};

//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        int n  = nums.size();
//        if (n == 0) {
//            return 0;
//        }
//        vector<int> memo(n, -1);
//        memo[n - 1] = nums[n - 1];
//        for (int i = n - 2; i >= 0; i--) {
//            for (int j = i; j < n; j ++) {
//                memo[i] = max(memo[i], nums[j] + (j + 2 < n ? memo[j + 2] : 0));
//            }
//        }
//
//        return memo[0];
//    }
//};