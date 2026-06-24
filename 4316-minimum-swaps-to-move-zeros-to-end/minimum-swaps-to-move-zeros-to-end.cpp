class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zeros=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zeros++;
            }
        }
        int nonzero=0;
        for(int i=n-1;i>=n-zeros;i--)
        {
            if(nums[i]==0)
            {
                nonzero++;
            }

        }
        return zeros-nonzero;
    }
};