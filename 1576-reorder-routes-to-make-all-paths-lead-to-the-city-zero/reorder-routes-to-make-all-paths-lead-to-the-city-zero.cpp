class Solution {
public:
int dfs(vector<vector<int>> &adj,vector<int> &vis,int node)
{
    int count=0;

    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[abs(it)])
        {
            count+=dfs(adj,vis,abs(it))+(it>0);

        }
    }
return count;
}
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(-it[0]);
        }
        vector<int> vis(n,0);
return dfs(adj,vis,0);

        
    }
};