class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0); 

        for (int i = n - 1; i >= 0; i--) {
            int mx = 0;
            int best = 0;

            for (int len = 1; len <= k && i + len - 1 < n; len++) {
                mx = max(mx, arr[i + len - 1]);
                best = max(best, mx * len + dp[i + len]);
            }
            dp[i] = best;
        }
        return dp[0];
    }
};