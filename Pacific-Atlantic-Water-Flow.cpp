class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        int m = heights.size();
        int n = heights[0].size();
        visited[row][col] = true;

        vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto [dr, dc] : dir) {
            int newr = row + dr;
            int newc = col + dc;
            if (newr >= 0 && newr < m && newc >= 0 && newc < n && 
                !visited[newr][newc] && heights[newr][newc] >= heights[row][col]) {
                dfs(newr, newc, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        // Pacific → top row & left column
        for (int i = 0; i < n; i++) dfs(0, i, heights, pac);
        for (int i = 0; i < m; i++) dfs(i, 0, heights, pac);

        // Atlantic → bottom row & right column
        for (int i = 0; i < n; i++) dfs(m - 1, i, heights, atl);
        for (int i = 0; i < m; i++) dfs(i, n - 1, heights, atl);

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
