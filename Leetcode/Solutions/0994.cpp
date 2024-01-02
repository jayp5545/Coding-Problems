class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> que; // val,{row,col};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    que.push({0, {i, j}});
                }
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (! que.empty()) {
            int dist = que.front().first;
            int row = que.front().second.first;
            int col = que.front().second.second;
            que.pop();
            ans =  dist;
            for (int i = 0; i < 4; i++) {
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                    grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    que.push({dist + 1, {nrow, ncol}});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    return -1;
            }
        }
        return ans;
    }
};