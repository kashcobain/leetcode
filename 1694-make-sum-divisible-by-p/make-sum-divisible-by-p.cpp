class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long sum = 0;
        for (auto x : nums) sum += x;

        int rem = sum % p;
        if (rem == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = 0;

        int n = nums.size();
        vector<int> pre(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pre[i] = (pre[i - 1] + nums[i - 1]) % p;
        }

        int ans = n;

        for (int i = 1; i <= n; i++) {

            int curr = pre[i];

            int need = (curr - rem + p) % p;

            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }

            mp[curr] = i;
        }

        return ans == n ? -1 : ans;
    }
};
