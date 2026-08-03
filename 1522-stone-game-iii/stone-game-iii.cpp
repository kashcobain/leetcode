class Solution {
public:
    int solve(vector<int>& nums,vector<int> &dp,int i)
    {
        int n=nums.size();
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=INT_MIN)return dp[i];
        int sum=0;
        
        for(int j=i;j<min(i+3,n);j++)
        {
            sum+=nums[j];
            dp[i]=max(dp[i],sum - solve(nums, dp, j + 1));

        }
return dp[i];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n+1,INT_MIN);
        int ans=solve(stoneValue,dp,0);
        
        if (ans > 0) return "Alice";
        if (ans < 0) return "Bob";
        return "Tie";
    }
};