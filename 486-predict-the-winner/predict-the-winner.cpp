class Solution {
public:
    int  solve(vector<int> &nums,int i,int j,vector<vector<int>> &dp)
    {
        if(i==j)return nums[i];
        if(dp[i][j]!=-1)return dp[i][j];
        int takelft=nums[i]-solve(nums,i+1,j,dp);
        int takerght=nums[j]-solve(nums,i,j-1,dp);
        return dp[i][j]=max(takelft,takerght);


    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,0,n-1,dp)>=0;
        
    } 
};