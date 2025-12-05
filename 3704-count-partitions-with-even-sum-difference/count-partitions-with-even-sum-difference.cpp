class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        return sum%2==0?nums.size()-1:0;
    }
};