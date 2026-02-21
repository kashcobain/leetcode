class Solution {
public:
    bool dfs(vector<vector<char>>& grid,
             vector<vector<bool>>& vis,
             int x, int y,
             int parentX, int parentY) {

        vis[x][y] = true;
        int m = grid.size();
        int n = grid[0].size();

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i = 0; i < 4; i++) {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];

            if(newx >= 0 && newy >= 0 &&
               newx < m && newy < n &&
               grid[newx][newy] == grid[x][y]) {

                if(!vis[newx][newy]) {
                    if(dfs(grid, vis, newx, newy, x, y))
                        return true;
                }
                else if(newx != parentX || newy != parentY) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    if(dfs(grid, vis, i, j, -1, -1))
                        return true;
                }
            }
        }

        return false;
    }
};