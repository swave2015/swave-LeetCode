#include <vector>

using namespace std;
//209
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //define a silding window to contain sub string
        //siliding window range is [l, ..., r]
        int l = 0, r = -1;
        int res = nums.size() + 1;
        int sum = 0;
        while(l < nums.size()) {
            if(r + 1 < nums.size() && sum < s) {
                sum += nums[r++];
            } else {
                sum -= nums[++l];
            }
            if(sum >= s) {
                res = min(res, r - l + 1);
            }
        }
        if(res == nums.size() + 1) {
            return 0;
        } else {
            return res;
        }
    }
};
