#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> record;
        for(int i = 0; i < nums.size(); i++) {
            if(record.find(nums[i]) != record.end()) {
                return true;
            }
            record.insert(nums[i]);
            if(record.size() == k + 1) {
                // can't delete element in an Unordered Set by index
                //record.erase(i - k);
                record.erase(nums[i - k]);
            }
        }
        return false;
    }
};