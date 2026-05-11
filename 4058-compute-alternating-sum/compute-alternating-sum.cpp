class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sign=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]*sign;
            sign=-sign;

        }
        return sum;
    }
};