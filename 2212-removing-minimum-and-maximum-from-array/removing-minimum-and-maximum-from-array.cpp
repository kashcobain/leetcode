class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();
        int mini = min_element(nums.begin(), nums.end()) - nums.begin();

        int n = nums.size();

        int a = max(maxi, mini) + 1;

        int b = n - min(maxi, mini);

        int c = min(maxi, mini) + 1 + n - max(maxi, mini);

        return min(a, min(b, c));
    }
};