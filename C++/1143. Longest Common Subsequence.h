#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo = vector<vector<int>>(text1.length(), vector<int>(text2.length(), -1));

        return  getMaxLength(text1, text2, text1.length() - 1, text2.length() - 1);
    }

private:
    vector<vector<int>> memo;

    int getMaxLength(const string& s1, const string& s2, int m, int n) {
        if (m < 0 || n < 0) {
            return 0;
        }
        if (memo[m][n] != -1) {
            return memo[m][n];
        }
        int res = 0;
        if (s1[m] == s2[n]) {
            res =  1 + getMaxLength(s1, s2, m - 1, n - 1);
        } else {
            res = max(getMaxLength(s1, s2, m - 1, n), getMaxLength(s1, s2, m, n - 1));
        }
        memo[m][n] = res;
        return res;
    }
};