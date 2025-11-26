class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=nums[0]+k,right=nums[n-1]-k;
        int res=nums[n-1]-nums[0];
                for(int i=1;i<n;i++)
        {
            int maxi=max(nums[i-1]+k,right);
            int mini=min(left,nums[i]-k);
        res=min(res,maxi-mini);


        }
        return res;
    }
};