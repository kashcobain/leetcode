class Solution {
public:
    int reverseNum(int n) {
        int res = 0;
        while (n > 0) {
            int digit = n % 10;
            res = res * 10 + digit;
            n /= 10;
        }
        return res;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int j = 0; j < nums.size(); j++) {
            

            if (mp.find(nums[j]) != mp.end()) {
                ans = min(ans, j - mp[nums[j]]);
            }
            int rev = reverseNum(nums[j]);
            mp[rev] = j;
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};