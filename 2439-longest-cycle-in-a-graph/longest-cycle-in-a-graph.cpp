class Solution {
public:
    int maxlen=-1;
    void dfs(int cyclelength,int node,vector<int> &vis,vector<int> &currpath,vector<int> &edges)
    {
        cyclelength++;
        currpath[node]=cyclelength;
        vis[node]=1;
        int nbr=edges[node];
        if(nbr!=-1)
        {
            if(!vis[nbr])
            {
                dfs(cyclelength,nbr,vis,currpath,edges);
            }
            else if(currpath[nbr]!=0){
                int curcyclen=currpath[node]-currpath[nbr]+1;
                maxlen=max(maxlen,curcyclen);
            }
            
        }
        currpath[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> vis(n,0);
        vector<int> currpath(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
            {
                dfs(0,i,vis,currpath,edges);
            }
        }
        return maxlen;

    }
};