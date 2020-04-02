#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// class Solution {
// private:
//     vector<vector<int>> res;
//     unordered_map<int, vector<int>> used;

//     void findPermute(vector<int>& nums, vector<int> c, int level) {
//         level++;
//         if (c.size() == nums.size()) {
//             res.push_back(c);
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             if (!used[i][1]) {
//                 used[i][0] = level;
//                 if(i > 0 && nums[i] == nums[i - 1] && used[i][0] == used[i - 1][0]) {
//                     continue;
//                 }
//                 c.push_back(nums[i]);
//                 used[i][1] = true;
//                 findPermute(nums, c, level);
//                 c.pop_back();
//                 used[i][1] = false;
//             }
//         }

//         return;
//     }

// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<int> c;
//         int level = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             used.insert(make_pair(i , vector<int>(2, 0)));
//         }
//         findPermute(nums, c, level);

//         return res;
//     }
// };

class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;

    void findPermute(vector<int>&nums, vector<int> c) {
        if (c.size() == nums.size()) {
            res.push_back(c);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;
                c.push_back(nums[i]);
                used[i] = true;
                findPermute(nums, c);
                c.pop_back();
                used[i] = false;
            }
        }

        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used = vector<bool>(nums.size(), false); // true if nums[i] is used
        vector<int> c;
        findPermute(nums, c);

        return res;
    }
};