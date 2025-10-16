class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return false;
        if(n==1)return false;
        if(n==2)return (nums[1]==nums[0]);
        vector<bool> dp(n,false);
        dp[0]=false;
        if(nums[0]==nums[1]) dp[1]=true;
        
        if(nums[2]==nums[1] && nums[1]==nums[0]) dp[2]=true;
        if(nums[2]==nums[1]+1 && nums[1]==nums[0]+1) dp[2]=true;
        if(n==3)return dp[2];
        for(int i=3;i<n;i++)
        {
            if(nums[i]==nums[i-1] && dp[i-2]) dp[i]=true;
            if(nums[i]==nums[i-1]&& nums[i-1]==nums[i-2] && dp[i-3])dp[i]=true;
            if(nums[i]==nums[i-1]+1 && nums[i-1]==nums[i-2]+1 && dp[i-3])dp[i]=true;
        }
        return dp[n-1];
    }
};