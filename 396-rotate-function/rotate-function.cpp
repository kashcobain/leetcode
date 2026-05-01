class Solution {
public:
    
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            dp[0]+=i*nums[i];
        }
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1]+sum-n*nums[n-i];
        }
        int ans=INT_MIN;
        for(int i=0;i<=n;i++)
        {
            ans=max(ans,dp[i]);

        }
        return ans;
    }
};