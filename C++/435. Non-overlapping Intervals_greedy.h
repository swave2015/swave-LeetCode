#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) {
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), compare);
        int res = 1;
        int pre = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[pre][1]) {
                res++;
                pre = i;
            }
        }

        return intervals.size() - res;
    }
};