class Solution {
public:
            bool dfscheck(int node,vector<int> &vis,vector<int> &pathvis,vector<vector<int>>& graph,vector<int> &check)
            {
                vis[node]=1;
                pathvis[node]=1;
                check[node]=0;
                for(auto it:graph[node])
                {
                    if(!vis[it])
                    {
                        if(dfscheck(it,vis,pathvis,graph,check)==true)
                        {check[node]=0;
                            return true;
                        }
                    }
                    else if(pathvis[it])
                    { check[node]=0;
                        return true;
                    }
                }
                check[node]=1;
                pathvis[node]=0;
                return false;
            }
            //image mein ye sab unvisited honge kyuki kisi ne unhe poora traverse nhi kiya or wo ab bhi vis or pathvis 1 rahenge agar code mein wo wapas aa jata tohi zero hota
     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        //keep marks of same node
        vector<int> check(n,0);
        vector<int> pathvis(n,0);
        vector<int> safenodes;
        for(int i=0;i<n;i++){
            if(!vis[i])
            {
                dfscheck(i,vis,pathvis,graph,check); 
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1)safenodes.push_back(i);
        }
        return safenodes;

        
        
        
    }
};