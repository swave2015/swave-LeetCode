#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//bool compare(const pair<char, int>& a, const pair<char, int>& b) {
//    return a.second > b.second;
//}
//
//
//class Solution {
//public:
//    int longestPalindrome(string s) {
//        if(s.size() == 0) {
//            return 0;
//        }
//        unordered_map<char, int> map;
//        for (int i = 0; i < s.size(); i++) {
//            map[s[i]]++;
//        }
//        vector<pair<char, int>> vec(map.begin(), map.end());
//        sort(vec.begin(), vec.end(), compare);
//        int res = 0;
//        for (int i = 0; i < vec.size(); i++) {
//            if (vec[i].second != 1) {
//                int len = vec[i].second / 2 * 2;
//                res += len;
//                vec[i].second -= len;
//            }
//        }
//        for (int i = 0; i < vec.size(); i++) {
//            if (vec[i].second == 1) {
//                res++;
//                break;
//            }
//        }
//
//        return res;
//    }
//};
class Solution {
public:
    int longestPalindrome(string s) {
        // actually it just assign index 0 to value 0, and other index assign value 0 automatically
        // if u initial like " freq[128] = {1}; " only index 0 will be assigned value as 1,
        // all else index will be auto assigned value 0;
        int freqs[128] = {0};
        int res = 0;
        for (const char c : s) {
            freqs[c]++;
        }
        int add = 0;
        for (const int freq : freqs) {
            res += freq / 2 * 2;
            if (freq % 2 != 0) {
                add = 1;
            }
        }

        return res + add;
    }
};