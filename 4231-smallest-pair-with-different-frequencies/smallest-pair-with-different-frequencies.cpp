class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int a=nums[0];
        int b=-1;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]!=mp[a])
            {
                b=nums[i];
                break;

            }
        }
        if(b==-1)return {-1,-1};
        else{
            return {a,b};
        }
    }
};