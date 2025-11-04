#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
       
        if (a.second != b.second)
            return a.second > b.second;
 
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int,int> mp;

       
            for (int j = i; j < i + k; j++) {
                mp[nums[j]]++;
            }
            vector<pair<int,int>> freq;
            for (auto &it : mp) {
                freq.push_back({it.first, it.second});
            }
            sort(freq.begin(), freq.end(), cmp());
            int xsum = 0;
            for (int l = 0; l < (int)freq.size() && l < x; l++) {
                xsum += freq[l].first * freq[l].second;
            }

            ans.push_back(xsum);
        }

        return ans;
    }
};