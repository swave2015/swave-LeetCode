#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    int m, n;
    int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        visited[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1') {
                dfs(grid, newx, newy);
            }
        }

        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        m = grid.size();
        if (m == 0) {
            return res;
        }
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};