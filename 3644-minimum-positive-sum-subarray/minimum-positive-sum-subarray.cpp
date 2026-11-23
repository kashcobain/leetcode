class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }
        int ans=INT_MAX;
        for(int i=l;i<=r;i++)
        {
            for(int j=0;j+i<=n;j++)
            {
                int sum=prefix[j+i]-prefix[j];
                if(sum>0 && sum<ans)ans=sum;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};