class Solution {
public:
    int solve(int i,int j, vector<int> &bal,vector<vector<int>> &dp)
    {
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=-1e9;
        for(int k=i;k<=j;k++)
        {
            int coins=bal[i-1]*bal[k]*bal[j+1]+solve(i,k-1,bal,dp)+solve(k+1,j,bal,dp);
            ans=max(ans,coins);
        }
return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> bal=nums;
        bal.insert(bal.begin(),1);
        bal.push_back(1);
        int n=bal.size();
        int k=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(1,k,bal,dp);

        
    }
};