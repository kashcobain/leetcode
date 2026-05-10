class Solution {
public:
    int solve(int ind,vector<int>& nums,vector<int> &dp)
    {
        int n=nums.size();
        if(ind==n-1)return 0;
        int ans=INT_MAX;
        if(dp[ind]!=-1)return dp[ind];
        for(int j=ind+1;j<min(ind+nums[ind]+1,n);j++)
        {
            int jump=solve(j,nums,dp);
            if(jump!=INT_MAX)
            {
                ans=min(ans,1+jump);

            }
            
    
        }
        return dp[ind]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);

        for(int ind=n-2;ind>=0;ind--)
        {
             int ans=INT_MAX;
            for(int j=ind+1;j<min(ind+nums[ind]+1,n);j++)
        {
            int jump=dp[j];
            if(jump!=INT_MAX)
            {
                ans=min(ans,1+jump);

            }
            
    
        }
        dp[ind]=ans;

        }
        return dp[0];

        
    }
};