class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
       int cnt=0;
       int prev=INT_MIN;
       for(int i=0;i<n;i++)
       {
        int curr=min(max(nums[i]-k,prev+1),nums[i]+k);
        if(curr>prev)
        {
            cnt++;
            prev=curr;
        }
       }

 return cnt;       
    }
};