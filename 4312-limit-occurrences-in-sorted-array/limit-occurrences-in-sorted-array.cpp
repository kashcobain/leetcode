class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
           mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            for(int i=0;i<min(it.second,k);i++)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};