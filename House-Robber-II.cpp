class Solution {
public:
    int robLinear(vector<int>& nums, int l, int r) {
        int n = r-l+1;
        if(n==1) return nums[l];
        vector<int> dp(n,0);
        dp[0] = nums[l];
        dp[1] = max(nums[l], nums[l+1]);

        for(int i=2; i<n; i++) {
            dp[i] = max(nums[l+i] + dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        // Case 1: rob houses [0 ... n-2]
        int case1 = robLinear(nums, 0, n-2);
        // Case 2: rob houses [1 ... n-1]
        int case2 = robLinear(nums, 1, n-1);

        return max(case1, case2);
    }
};
