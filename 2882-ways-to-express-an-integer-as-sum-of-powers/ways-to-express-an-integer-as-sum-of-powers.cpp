class Solution {
public:
    int solve(int i,int n,vector<vector<int>> &dp,vector<int> &nums)
    {   if(i==0)
    {
         if(n == 0) return dp[i][n] = 1;
        return dp[i][n] = (nums[i] == n);
    }
        int mod=1e9+7;
        int take=0;
        if(dp[i][n]!=-1)return dp[i][n];
        if(nums[i]<=n)
        {
             take=solve(i-1,n-nums[i],dp,nums);
           
        }
        int nt=solve(i-1,n,dp,nums);
        return dp[i][n]=(take+nt)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<int> nums;
        for(int i = 1; ; i++)
        {
            long long val = 1;

            for(int j = 0; j < x; j++)
                val *= i;

            if(val > n)
                break;

            nums.push_back(val);
        }
        vector<vector<int>> dp(nums.size(),vector<int>(n+1,-1));
        return solve(nums.size()-1,n,dp,nums);
    }
};