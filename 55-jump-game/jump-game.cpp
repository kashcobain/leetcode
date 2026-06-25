class Solution {
public:
    bool solve(int ind,vector<int> &nums,vector<int> &dp)
    {
        int n=nums.size();
        if(ind==n-1)return true;
        if(nums[ind]==0)return false;
        if(dp[ind]!=-1)return dp[ind];
        int reach=ind+nums[ind];
        for(int jump=ind+1;jump<=reach;jump++)
        {
            if(jump<n && solve(jump,nums,dp))
            {
                return dp[ind]=true;
            }
        }
return dp[ind]=false;

    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
        
    }
};