class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        vis[r][c] = 1;
        int perimeter = 0;
        
        // directions: up, right, down, left
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
           
            if(nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == 0)
                perimeter++;
            
            else if(!vis[nr][nc])
                perimeter += dfs(grid, vis, nr, nc);
        }
        
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    return dfs(grid, vis, i, j);
                }
            }
        }
        return 0;
    }
};  