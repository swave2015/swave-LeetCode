#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    } else {
        return a[1] < b[1];
    }
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> memo(intervals.size(), 1);
        for (int i = 1; i < intervals.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (intervals[i][0] >= intervals[j][1]) {
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < memo.size(); i++) {
            res = max(res, memo[i]);
        }

        return intervals.size() - res;
    }
};