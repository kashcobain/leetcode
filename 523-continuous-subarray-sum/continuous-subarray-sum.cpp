class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;

        
        if (k == 0) {
         for (int i = 1; i < n; i++) {
                if (nums[i] == 0 && nums[i - 1] == 0) return true;
            }
            return false;
        }

        vector<int> presum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = (presum[i - 1] + nums[i - 1]) % k;
        }

        unordered_map<int,int> mp;
        mp[0] = 0;  

        for (int i = 1; i <= n; i++) {
            int rem = presum[i];

            if (mp.find(rem) != mp.end()) {
                int prev = mp[rem];   
                if (i - prev >= 2) {     
                    return true;
                }
            } else {
                mp[rem] = i; 
            }
        }
        return false;
    }
};
