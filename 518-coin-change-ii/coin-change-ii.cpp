class Solution {
public:
    int solve(vector<int>& coins,int idx,int amt,  vector<vector<int>> &dp)
    {
        if(dp[idx][amt]!=-1)
        {
            return dp[idx][amt];
        }
        if(amt==0)return 1;
        if(idx==0)return 0;
        int skip=solve(coins,idx-1,amt,dp);
        int take=0;
        if(coins[idx-1]<=amt)
        {
            take=solve(coins,idx,amt-coins[idx-1],dp);
        }
            return dp[idx][amt]=take+skip;
        
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
      return  solve(coins,n,amount,dp);
    }
};