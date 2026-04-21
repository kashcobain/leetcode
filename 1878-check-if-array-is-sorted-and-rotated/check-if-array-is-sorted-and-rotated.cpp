class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int i = 0;

        while (i < n - 1) {
            if (nums[i] > nums[i + 1]) {
                count++;
            }
            i++;
        }
        if (nums[n - 1] > nums[0]) {
            count++;
        }

        if (count <= 1) {
            return true;
        }
        else {
            return false;
        }
    }
};