class Solution {
public:
    int solve(int i, int j, vector<int> &prices, vector<vector<int>> &dp)
    {
        int n = prices.size();
        if(i >= n) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(j) { 
           return dp[i][j] = max(
                solve(i+1, 0, prices, dp) - prices[i], 
                solve(i+1, 1, prices, dp)             
            );
        } 
        else { 
           return dp[i][j] = max(
                prices[i] + solve(i+1, 1, prices, dp), 
                solve(i+1, 0, prices, dp)             
            );
        }

      
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};