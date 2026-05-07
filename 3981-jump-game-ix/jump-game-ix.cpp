class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> suf(n),pre(n),res(n);
        int maxi=nums[0];
        int mini=nums[n-1];
        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
            }
            pre[i]=maxi;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<mini)
            {
                mini=nums[i];
            }
            suf[i]=mini;
        }
        res[n-1]=pre[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(pre[i]>suf[i+1])
            {
                res[i]=res[i+1];
            }
            else{
                res[i]=pre[i];
            }

        }
        return res;
    }
};