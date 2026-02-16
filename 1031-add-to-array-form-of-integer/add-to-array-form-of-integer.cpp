class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int n = nums.size();
        int carry = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            int sum = nums[i] + (k % 10) + carry;
            nums[i] = sum % 10;
            carry = sum / 10;
            k /= 10;
        }

        while(k > 0 || carry > 0)
        {
            int sum = (k % 10) + carry;
            nums.insert(nums.begin(), sum % 10);
            carry = sum / 10;
            k /= 10;
        }

        return nums;
    }
};
