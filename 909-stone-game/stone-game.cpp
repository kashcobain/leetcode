class Solution {
public:
    int solve(vector<int>& nums,int i,int j,vector<vector<int>> &dp)
    {
        if(i==j)return nums[i];
        if(dp[i][j]!=-1)return dp[i][j];
        int t1=nums[i]-solve(nums,i+1,j,dp);
        int t2=nums[j]-solve(nums,i,j-1,dp);
        return dp[i][j]=max(t1,t2);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(piles,0,n-1,dp)>0;

    }
};