class Solution {
public:
    int solve(int i,int j,int k,vector<int> &prices,vector<vector<vector<int>>> &dp)
    {
        int n=prices.size();
        if(i==n)
        {
            return 0;
        }
        if(k==0)
        {
            return 0;
        }
        if(dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }
        if(j)
        {
            dp[i][j][k]=max(-prices[i]+solve(i+1,0,k,prices,dp),solve(i+1,1,k,prices,dp));
            
        }
        else{
            dp[i][j][k]=max(prices[i]+solve(i+1,1,k-1,prices,dp),solve(i+1,0,k,prices,dp));
        }
        return dp[i][j][k];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);

        
    }
};