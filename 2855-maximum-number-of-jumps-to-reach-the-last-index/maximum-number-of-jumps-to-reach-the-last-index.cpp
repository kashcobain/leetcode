class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[n-1]=0;
    for(int ind=n-2;ind>=0;ind--)
    {
        int ans = INT_MIN;
        for(int i = ind + 1; i < n; i++)
        {
            if(abs(nums[i] - nums[ind]) <= target)
            {
                int next =dp[i];

                
                if(next != INT_MIN)
                {
                    ans = max(ans, 1 + next);
                }
            }
        }
        dp[ind]=ans;

    }
if(dp[0]==INT_MIN)return -1;
        
        else

        {return dp[0];}
    }
};