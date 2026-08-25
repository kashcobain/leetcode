class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++)
        {
            adj[edges[i]].push_back(i);
        }

        vector<int> ans;
        unordered_map<int, long long> mp;

        long long sum = 0;
        long long maxi = LLONG_MIN;

        for(int i = 0; i < n; i++)
        {
            for(auto it : adj[i])
            {
                sum += it;
            }

            mp[i] = sum;

            if(sum > maxi)
            {
                maxi = sum;
            }

            sum = 0;
        }

        int node = INT_MAX;

        for(auto it : mp)
        {
            if(it.second == maxi)
            {
                node = min(it.first, node);
            }
        }

        return node;
    }
};