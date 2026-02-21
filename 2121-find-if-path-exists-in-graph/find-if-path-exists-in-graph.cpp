class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<bool> &vis,int source)
    {
        vis[source]=true;
        for(auto it:adj[source])
        {
            if(!vis[it])
            {
                dfs(adj,vis,it);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        dfs(adj,vis,source);
        if(vis[destination])
        {
            return true;
        }
        else{
            return false;
        }

    }
};