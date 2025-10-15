class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int ans=-1;
    sort(nums.begin(),nums.end());
      for(int i=nums.size()-1;i>=0;i--)
      {
        if(mp.find(-1*nums[i])!=mp.end())
        {
            ans=max(ans,nums[i]);
        }
      }
      return ans;
    }
};