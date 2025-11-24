class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0,maj=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                maj=nums[i];
            }
            if(nums[i]==maj)
            {
                count++;
            }
            else{
                count--;
            }
        }
        return maj;
    }
};