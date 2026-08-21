class Solution {
public:
    int solve(int i, int tar, vector<vector<int>>& dp, vector<int>& nums)
    {
        if(i == 0)
        {
            if(tar == 0 && nums[0] == 0)
                return 2;

            if(tar == 0 || tar == nums[0])
                return 1;

            return 0;
        }

        if(dp[i][tar] != -1)
            return dp[i][tar];

        int take = 0;

        if(nums[i] <= tar)
        {
            take = solve(i - 1, tar - nums[i], dp, nums);
        }

        int nt = solve(i - 1, tar, dp, nums);

        return dp[i][tar] = take + nt;
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;

        for(auto it : nums)
            sum += it;

        if(target > sum || target < -sum)
            return 0;

        if((target + sum) % 2 != 0)
            return 0;

        int tar = (target + sum) / 2;

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

        return solve(n - 1, tar, dp, nums);
    }
};