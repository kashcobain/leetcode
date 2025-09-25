class Solution {
 public:
     int minimumTotal(vector<vector<int>>& triangle) {
         int n = triangle.size();
         vector<vector<int>> dp(n, vector<int>(n, 0));

         // Base case: last row = same as triangle
         for (int i = 0; i < n; i++) {
             dp[n - 1][i] = triangle[n - 1][i];
         }

         // Fill DP table from bottom-2 row to top
         for (int r = n - 2; r >= 0; r--) {
             for (int i = 0; i < triangle[r].size(); i++) {
                 int down = dp[r + 1][i];
                 int diag = dp[r + 1][i + 1];
                 dp[r][i] = triangle[r][i] + min(down, diag);
             }
         }

         return dp[0][0];
    }
};