class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // Early return for edge case
        if(nums.size() == 2) return true;

        // Check all possible starting positions for the two adjacent subarrays
        for(int i = 0; i <= nums.size() - (2 * k); ++i) {
            bool firstSubArray = true, secondSubArray = true;

            // Check if first subarray [i, i+k-1] is strictly increasing
            for(int j = i; j < i + k - 1; ++j) {
                if(nums[j + 1] <= nums[j]) {
                    firstSubArray = false;
                    break;
                }
            }
            
            // Check if second subarray [i+k, i+2k-1] is strictly increasing
            for(int j = i + k; j < i + (2 * k) - 1; ++j) {
                if(nums[j + 1] <= nums[j]) {
                    secondSubArray = false;
                    break;
                }
            }

            // If both subarrays are strictly increasing, return true
            if(firstSubArray && secondSubArray) return true;
        }
        return false;
    }
};