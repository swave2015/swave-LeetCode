#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void findSubsets(vector<int>& nums, int start, vector<int> c) {
        res.push_back(c);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            c.push_back(nums[i]);
            findSubsets(nums, i + 1; c);
            c.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> c;
        sort(nums.begin(), nums.end());
        findSubsets(nums, 0, c);

        return res;
    }
};

int main() {

}