#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// class Solution {
// public :
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());
//         int res = 0;
//         for (int i = 0; i < g.size(); i++) {
//             for (int j = 0; j < s.size(); j++) {
//                 if (s[j] >= g[i]) {
//                     s.erase(s.begin() + j);
//                     res++;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int gi = 0, si = 0, res = 0;
        while(gi < g.size() && si < s.size()) {
            if (g[gi] <= s[si]) {
                gi++, si++, res++;
            } else {
                gi++;
            }
        }

        return res;
    }
};
