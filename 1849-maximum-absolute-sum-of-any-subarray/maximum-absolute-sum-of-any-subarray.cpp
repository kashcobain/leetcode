class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int sum;
        for(int i=0;i<n;i++)
        {
            if(sum<=0)
            {
                sum=0;
            }
            sum+=nums[i];
            maxi=max(maxi,sum);
        }
        int bum;
        for(int i=0;i<n;i++)
        {
            if(bum>=0)
            {
                bum=0;
            }
            bum+=nums[i];
            mini=min(mini,bum);
        }
        return max(maxi,-1*mini);
    }
};