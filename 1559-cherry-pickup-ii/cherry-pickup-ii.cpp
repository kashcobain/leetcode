class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1e8)));

        
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                if(j == k)
                    dp[n-1][j][k] = grid[n-1][j];
                else
                    dp[n-1][j][k] = grid[n-1][j] + grid[n-1][k];
            }
        }


        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {

                    int maxi = -1e8;

                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {

                            int nj = j + dj1;
                            int nk = k + dj2;

                            if(nj >= 0 && nj < m && nk >= 0 && nk < m) {

                                int val;
                                if(j == k)
                                    val = grid[i][j];
                                else
                                    val = grid[i][j] + grid[i][k];

                                val += dp[i+1][nj][nk];

                                maxi = max(maxi, val);
                            }
                        }
                    }

                    dp[i][j][k] = maxi;
                }
            }
        }

        return dp[0][0][m-1];
    }
};