class Solution {
public:
    void dfs(int i,vector<int> adj[],vector<int> &vis,vector<int> &comp)
    {
        vis[i]=1;
        comp.push_back(i);
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,comp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
adj[it[1]].push_back(it[0]);
        }
        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vector<int> comp;
               
                dfs(i,adj,vis,comp);
                int nodes=comp.size();
                int degresum=0;
                for(int it:comp)
                {
                    degresum+=adj[it].size();
                }
                int compedge=degresum/2;
                int reqedges=nodes*(nodes-1)/2;
                if(compedge==reqedges)
                {
                    count++;
                }

            }
        }
        return count;
    }
};