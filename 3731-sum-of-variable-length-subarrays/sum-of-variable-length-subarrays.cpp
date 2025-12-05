class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();

       
        vector<long long> presum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        long long ans = 0;

      
        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]);
            long long subSum = presum[i + 1] - presum[start];
            ans += subSum;
        }

        return (int)ans;
    }
};
