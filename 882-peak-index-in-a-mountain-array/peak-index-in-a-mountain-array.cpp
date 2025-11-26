class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high)
        {
           int mid=(low+high)/2;

        if(nums[mid]>nums[mid+1] &&nums[mid]>nums[mid-1])
        {
            return mid;
        }
        else if(nums[mid]>nums[mid+1])
        {
            high=mid;
        }
        else{
            low=mid+1;
        }
        }
        return -1;
    }
};
//*upper_bound(nums.ebgin(),nums.end(),number) se diect number milta hai