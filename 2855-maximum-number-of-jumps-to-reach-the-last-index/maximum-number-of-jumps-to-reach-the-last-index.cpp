class Solution {
public:

    int jumps(int ind, vector<int>& nums, int target, vector<int>& dp)
    {
        int n = nums.size();
        if(ind == n - 1)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        int ans = INT_MIN;
        for(int i = ind + 1; i < n; i++)
        {
            if(abs(nums[i] - nums[ind]) <= target)
            {
                int next = jumps(i, nums, target, dp);

                
                if(next != INT_MIN)
                {
                    ans = max(ans, 1 + next);
                }
            }
        }

        return dp[ind] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int val = jumps(0, nums, target, dp);

        if(val == INT_MIN)
            return -1;

        return val;
    }
};