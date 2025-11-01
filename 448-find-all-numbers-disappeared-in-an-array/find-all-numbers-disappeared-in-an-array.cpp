class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> mp;
       for(int i=0;i<n;i++)
       {
        mp.insert(nums[i]);
        
       }
       vector<int> ans;
       for(int i=1;i<n+1;i++)
       {
        if(mp.find(i)==mp.end())
        {
            ans.push_back(i);
        }
       }
       return ans;
    }
};