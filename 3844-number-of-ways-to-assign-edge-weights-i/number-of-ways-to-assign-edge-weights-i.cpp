class Solution {
public:
    int power(long long a,long long b)
    {
        int mod=1e9+7;

        long long ans=1;
        while(b>0)
        {
            if(b&1)
            {
                ans=(ans*a)%mod;
            }
                a=(a*a)%mod;
            
            b>>=1;

        }
return (int)ans;
    }
    int dfs(int node,vector<int> &vis,vector<int> adj[])
    {
        vis[node]=1;
        int ans=0;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                ans=max(ans,1+dfs(it,vis,adj));
            }
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int mod=1e9+7;
        int n=edges.size()+2;
        vector<int> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int height = dfs(1,vis,adj);
return power(2,height-1);
        
    }
};