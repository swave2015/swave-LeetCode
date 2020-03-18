#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(record.find(complement) != record.end()) {
                int res[2] = {record[complement], i};
                return vector<int>(res, res + 2);
            } else {
                record[nums[i]] = i;
            }
        }
        throw invalid_argument("the input has no solution");
    }
};