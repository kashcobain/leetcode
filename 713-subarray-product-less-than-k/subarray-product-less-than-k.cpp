class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        long prod=1;
        int left=0,right=0;
        int n=nums.size();
        int totalSub=0;

        while(right<n){
            prod*=nums[right];

            while(left<=right && prod>=k){
                prod/=nums[left];
                left++;
            }

             totalSub+=right-left+1;
            right++;
        }

        return totalSub;
    }
};