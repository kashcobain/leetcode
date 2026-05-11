class Solution {
public:
    int minimumSum(int num) {
        vector<int> nums;
        while(num   >0)
        {
            int digit=num%10;
            nums.push_back(digit);
            num=num/10;

        }
        sort(nums.begin(),nums.end());
        int num1=nums[0]*10+nums[3];
        int num2=nums[1]*10+nums[2];
        return num1+num2;
    }
};