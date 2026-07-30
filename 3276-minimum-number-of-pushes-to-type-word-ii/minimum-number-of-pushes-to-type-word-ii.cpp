class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        vector<pair<int ,char>> vt;
        for(auto it:word)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            vt.push_back({it.second,it.first});
        }
        sort(vt.begin(),vt.end(),greater<pair<int,char>>());
        int ans=0;
        for(int i=0;i<vt.size();i++)
        {
            ans+=(i/8 + 1 )*(vt[i].first);
        }
        return ans;
    }
};