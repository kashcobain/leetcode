class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = 1;
        int count = 1; 

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int newr = i + dr[k];
            int newc = j + dc[k];

            if (newr >= 0 && newr < m && newc >= 0 && newc < n &&
                grid[newr][newc] == 1 && !vis[newr][newc]) {
                count += dfs(grid, newr, newc, vis);
            }
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int ans = dfs(grid, i, j, vis);
                    maxi = max(maxi, ans);
                }
            }
        }

        return maxi;
    }
};
