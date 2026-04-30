class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(k+1, -1e9)));

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                for(int c = 0; c <= k; c++) {

                    int addcost = (grid[i][j] == 0 ? 0 : 1);
                    int newcost = c + addcost;

                    if(newcost > k) continue;

                    // destination
                    if(i == n-1 && j == m-1) {
                        dp[i][j][c] = grid[i][j];
                        continue;
                    }

                    int best = -1e9;

                    if(j+1 < m)
                        best = max(best, dp[i][j+1][newcost]);

                    if(i+1 < n)
                        best = max(best, dp[i+1][j][newcost]);

                    if(best != -1e9)
                        dp[i][j][c] = grid[i][j] + best;
                }
            }
        }

        int ans = dp[0][0][0];
        return (ans == -1e9) ? -1 : ans;
    }
};