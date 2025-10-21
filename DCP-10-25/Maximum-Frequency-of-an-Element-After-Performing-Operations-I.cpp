class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int M = *max_element(nums.begin(), nums.end());
        vector<int> dp(M + 1, 0);
        int prev = 0, ans = 0;
        for (int i : nums){
            dp[i]++;
        }
        int curr = 0;
        for (int i = 0; i < k && i <= M; i++){
            curr += dp[i];
        }
        for (int i = 0; i <= M; i++){
            curr -= dp[i];
            if (i + k <= M){
                curr += dp[i + k];
            }
            if (i > 0){
                prev += dp[i - 1];
            }
            if (i > k + 1){
                prev -= dp[i - k - 1];
            }
            ans = max(ans, dp[i] + min(numOperations, prev + curr));
        }
        return ans;
    }
};