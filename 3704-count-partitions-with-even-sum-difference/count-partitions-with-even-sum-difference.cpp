class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int count=0;
        int sum1=0;
        for(int i=0;i<nums.size()-1;i++)
        {
           sum1+=nums[i];
           sum-=nums[i];
           if((sum-sum1)%2==0)
           {
            count++;
           }
        }
        return count;
    }
};