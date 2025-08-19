class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> k(n, 0);
        int sum = 0;  // keep outside loop
        long long ans = 0; // also outside

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0)
            {
                sum = 0;   // reset if non-zero
                k[i] = 0;
            }
            else
            {
                sum++;      // consecutive zeros
                k[i] = sum;
            }
        }

        for(int i = 0; i < n; i++)
        {
            ans += (long long)k[i];   // add contribution of each zero streak
        }

        return ans;
    }
};
