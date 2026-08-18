class Solution {
public:

    int solve(int i, int j, vector<int>& pre, vector<vector<int>>& dp) {
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for (int k = i + 1; k <= j; k++) {

            int left = pre[k] - pre[i];
            int right = pre[j + 1] - pre[k];

            if (left < right) {

                ans = max(ans,
                          left + solve(i, k - 1, pre, dp));
            }
            else if (right < left) {

                ans = max(ans,
                          right + solve(k, j, pre, dp));
            }

            else {

                ans = max(ans,
                          left + max(
                              solve(i, k - 1, pre, dp),
                              solve(k, j, pre, dp)
                          ));
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();
        vector<int> pre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + stoneValue[i];
        }

      
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, pre, dp);
    }
};