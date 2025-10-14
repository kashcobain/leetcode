class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int> keys;
        for(auto it:mp) keys.push_back(it.first);
        int n=keys.size();
        vector<int> dp(n,0);
        sort(keys.begin(),keys.end());
        dp[0]=keys[0]*mp[keys[0]];
        for(int i=1;i<n;i++)
        {
            int take=keys[i]*mp[keys[i]];
            int prev=upper_bound(keys.begin(),keys.begin()+i,keys[i]-2)-keys.begin()-1;
            if(prev>=0)take+=dp[prev];
            dp[i]=max(dp[i-1],take);
        }

       return dp[n-1]; 
    }
};