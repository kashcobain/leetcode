class Solution {
public:
struct cmp {
    bool operator()(const pair<int,int>& a,
                    const pair<int,int>& b)
    {
        if(a.first == b.first)
            return a.second > b.second;

        return a.first < b.first;
    }
};

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;

        }
        vector<pair<int,int>> temp;
        for(auto it:mp)
        {
            temp.push_back({it.second,it.first});
        }
        vector<int> ans;
        sort(temp.begin(),temp.end(),cmp());
        for(int i=0;i<temp.size();i++)
        {
            auto it=temp[i];
            int size=it.first;
            int value=it.second;
            while(size)
            {
                ans.push_back(value);
                size--;
            }
        }
        return ans;
    }
};