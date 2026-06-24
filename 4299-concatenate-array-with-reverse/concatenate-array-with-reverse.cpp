class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(2*n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=nums[i];
        }
        for(int i=n;i<2*n;i++)
        {
            ans[i]=nums[2*n-i-1];
        }

return ans;
        
    }
};