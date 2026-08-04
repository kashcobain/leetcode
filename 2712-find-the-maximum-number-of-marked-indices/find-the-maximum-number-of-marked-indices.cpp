class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mid = 0;
        int last = (n + 1) / 2;
        int ans = 0;

        while (mid < n / 2 && last < n) {
            if (2 * nums[mid] <= nums[last]) {
                ans += 2;
                mid++;
                last++;
            } else {
                last++;
            }
        }

        return ans;
    }
};