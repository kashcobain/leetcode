class Solution {
public:

    bool solve(int i, int j, int bal,
               vector<vector<char>>& grid,
               vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        
        if (bal < 0)
            return false;

       
        if (bal > m + n)
            return false;

     
        if (i == m - 1 && j == n - 1)
            return bal == 0;

       
        if (dp[i][j][bal] != -1)
            return dp[i][j][bal];

        bool down = false;
        bool right = false;

   
        if (i < m - 1) {

            if (grid[i + 1][j] == '(') {
                down = solve(i + 1, j, bal + 1, grid, dp);
            }
            else if (bal > 0) {
                down = solve(i + 1, j, bal - 1, grid, dp);
            }
        }

       
        if (j < n - 1) {

            if (grid[i][j + 1] == '(') {
                right = solve(i, j + 1, bal + 1, grid, dp);
            }
            else if (bal > 0) {
                right = solve(i, j + 1, bal - 1, grid, dp);
            }
        }

        return dp[i][j][bal] = down || right;
    }


    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        
        if (grid[0][0] == ')')
            return false;

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n + 1, -1)
            )
        );

        return solve(0, 0, 1, grid, dp);
    }
};
