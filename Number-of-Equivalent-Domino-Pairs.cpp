class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int> mp;  // normal map
        int ans = 0;

        for(auto &d : dominoes){
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            pair<int,int> key = {a, b};

            ans += mp[key];
            mp[key]++;
        }

        return ans;
    }
};
