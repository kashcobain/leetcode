class Solution {
public:

    int unequalTriplets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int x:nums)
        {
            mp[x]++;
        }
        vector<int> f;
        for(auto x:mp)
        {
            f.push_back(x.second);
        }
        int left=0;
       

      for(auto it:f)
      {
        int right=n-left-it;
        count+=left*it*right;
        left+=it;
      }
return count;
        
    }
};