class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        int last1=-1;
        int last2=-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                if(last2!=-1)
                {
                    ans=min(ans,abs(i-last2));
                }
                 last1=i;
            }
            if(nums[i]==2)
            {
                if(last1!=-1)
                {
                    ans=min(ans,abs(i-last1));
                }
                 last2=i;
            }
        }
        if(ans==INT_MAX)return -1;
        else return ans;
    }
};