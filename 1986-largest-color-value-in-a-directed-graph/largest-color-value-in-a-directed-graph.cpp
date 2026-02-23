class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();

        int ans=0;
        vector<vector<int>> adj(n);
        vector<vector<int>> cnt(n,vector<int>(26));
        vector<int> indegree(n,0);
        for( int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int> q;
        int processed=0;

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            processed++;
            cnt[f][colors[f]-'a']++;
            ans=max(ans,cnt[f][colors[f]-'a']);
            for(auto nbr:adj[f])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
                for(int j=0;j<26;j++)
            {
                cnt[nbr][j]=max(cnt[nbr][j],cnt[f][j]);
            }
            }
            

        }

        return processed==n?ans:-1;
    }
};