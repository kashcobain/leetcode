class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,
                               vector<int>(n, 0));
        for(int j = 0; j < n; j++) {
            dp[n-1][j] = matrix[n-1][j];
        }
        for(int i = n-2; i >= 0; i--) {

            for(int j = 0; j < n; j++) {

                int down =
                    matrix[i][j]
                    + dp[i+1][j];

                int leftDiag = 1e9;

                if(j-1 >= 0) {
                    leftDiag =
                        matrix[i][j]
                        + dp[i+1][j-1];
                }

                int rightDiag = 1e9;

                if(j+1 < n) {
                    rightDiag =
                        matrix[i][j]
                        + dp[i+1][j+1];
                }

                dp[i][j] =
                    min({down, leftDiag, rightDiag});
            }
        }

        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {

            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};