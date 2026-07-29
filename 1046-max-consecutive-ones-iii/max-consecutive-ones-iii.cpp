class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0;
        int ans=0;
        int left=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zeros++;
            }
            while(zeros>k)
            {
                    if(nums[left]==0)
                    {
                        zeros--;
                    }
                    left++;
            }
            if(zeros<=k)
            {
                ans=max(ans,i-left+1);
            }

        }
        return ans;
    }
};