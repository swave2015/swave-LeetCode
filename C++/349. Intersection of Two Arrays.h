#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record(nums1.begin(), nums1.end());
        set<int> res_set;
        for(int i = 0; i < nums2.size(); i++) {
            if(record.find(nums2[i]) != record.end()) {
                res_set.insert(nums2[i]);
            }
        }

        return vector<int>(res_set.begin(), res_set.end());
    }
};