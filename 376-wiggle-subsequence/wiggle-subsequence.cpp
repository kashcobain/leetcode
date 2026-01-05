class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int ups=1;
        int downs=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])ups=downs+1;
            if(nums[i]>nums[i+1])downs=ups+1;
        }
        return max(ups,downs);

        
    }
};