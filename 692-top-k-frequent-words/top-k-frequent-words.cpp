class Solution {
public:
 struct cmp{
        bool operator()(pair<int,string> &a,pair<int,string> &b)
        {
            if(a.first==b.first)
            {
                return a.second<b.second;
            }
            return a.first>b.first;
        }
 };

    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        unordered_map<string ,int> mp;
        for(auto it:words)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
          pq.push({it.second,it.first});
            while(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<string> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();

        }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};