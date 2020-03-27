#include <queue>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        assert (k > 0);
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        assert (k <= freq.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (unordered_map<int, int>::iterator iter = freq.begin();
             iter != freq.end(); iter++) {
            if(pq.size() >= k) {
                pq.push(make_pair(iter->second, iter->first));
                pq.pop();
            } else {
                pq.push(make_pair(iter->second, iter->first));
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};


int main() {
    int arr[] = {1, 1, 2, 3, 4, 4, 4, 5, 5};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> res = Solution().topKFrequent(nums, 2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}