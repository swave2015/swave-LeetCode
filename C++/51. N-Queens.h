#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<int> col, dia1, dia2;
    vector<vector<string>> res;

    void putQueen(int n, int index, vector<int> colRes) {
        if (index == n) {
            return res.push_back(generateBoard(colRes));
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
                colRes.push_back(i);
                col[i] = true;
                dia1[index + i] = true;
                dia2[index - i + n - 1] = true;
                putQueen(n, index + 1, colRes);
                colRes.pop_back();
                col[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
            }
        }

        return;
    }

    vector<string> generateBoard(vector<int> vec) {
        string s;
        for (int i = 0; i < vec.size(); i++) {
            s += '.';
        }
        vector<string> res(vec.size(), s);
        for (int i = 0; i < vec.size(); i++) {
            res[i][vec[i]] = 'Q';
        }

        return res;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) {
            return res;
        }
        col = vector<int>(n, false);
        dia1 = vector<int>(2 * n - 1, false);
        dia2 = vector<int>(2 * n -1, false);
        vector<int> colRes;
        putQueen(n, 0, colRes);

        return res;
    }
};