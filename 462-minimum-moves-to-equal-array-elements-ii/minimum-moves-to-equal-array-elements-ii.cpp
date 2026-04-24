class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i-1] + nums[i];
        }

        int mid = n / 2;

        int leftsum = (mid > 0) ? pre[mid - 1] : 0;
        int rightsum = pre[n - 1] - pre[mid];

        int leftcount = mid;
        int rightcount = n - mid - 1;

        int leftval = nums[mid] * leftcount - leftsum;
        int rightval = rightsum - nums[mid] * rightcount;

        return leftval + rightval;
    }
};