#include <queue>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        vector<bool> visited(n + 1, false);
        visited[n] = true;
        q.push(make_pair(n, 0));
        while (!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            int nextNum;
            for (int i = 0;;i++) {
                nextNum = num - i * i;
                if (nextNum < 0) {
                    break;
                } else if (nextNum == 0) {
                    return step + 1;
                }
                if (!visited[nextNum]) {
                    q.push(make_pair(nextNum, step + 1));
                }
            }
        }
        throw invalid_argument("No Solution");
    }
};