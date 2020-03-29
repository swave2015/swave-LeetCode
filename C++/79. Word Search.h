#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
private:
    int m, n;
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool searchWord(vector<vector<char>>& board, string word, int index, int startX, int startY) {
        if (index == word.size() - 1) {
            return board[startX][startY] == word[index];
        }
        if (board[startX][startY] == word[index]) {
            visited[startX][startY] = true;
            int nextX, nextY;
            for (int i = 0; i < 4; i++) {
                nextX = startX + d[i][0];
                nextY = startY + d[i][1];
                if (inArea(nextX, nextY) && !visited[nextX][nextY] &&
                        searchWord(board, word, index + 1, nextX, nextY)) {
                    return true;
                }
            }
            visited[startX][startY] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        assert(m != 0);
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                if (searchWord(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};