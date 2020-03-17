#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record;
        set<int> res_set;
        vector<int> res_vec;
        for(int i = 0; i < nums1.size(); i++) {
            record.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(record.find(nums2[i]) != record.end()) {
                res_set.insert(nums2[i]);
            }
        }
        for(set<int>::iterator iter = res_set.begin(); iter != res_set.end(); iter++) {
            res_vec.push_back(*iter);
        }
        return res_vec;
    }
};