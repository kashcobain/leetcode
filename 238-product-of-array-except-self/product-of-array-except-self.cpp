class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pro = 1;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            pro *= nums[i];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                ans.push_back(pro / nums[i]);
            } else {
                int product = 1;
                for (int j = 0; j < i; j++) {
                    product *= nums[j];
                }
                for (int l = i + 1; l < n; l++) {
                    product *= nums[l];
                }
                ans.push_back(product);
            }
        }

        return ans;
    }
};
