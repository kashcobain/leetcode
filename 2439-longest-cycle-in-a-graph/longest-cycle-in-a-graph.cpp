class Solution {
public:

    void dfs(int node,
             vector<int>& edges,
             vector<int>& vis,
             vector<int>& pathvis,
             vector<int>& depth,
             int d,
             int& ans)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        depth[node] = d;

        int next = edges[node];

        if(next != -1)
        {
            if(!vis[next])
            {
                dfs(next, edges, vis, pathvis, depth, d+1, ans);
            }
            else if(pathvis[next])
            {
                // cycle found
                ans = max(ans, d - depth[next] + 1);
            }
        }

        pathvis[node] = 0; // backtrack
    }

    int longestCycle(vector<int>& edges) {

        int n = edges.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> depth(n, 0);

        int ans = -1;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(i, edges, vis, pathvis, depth, 0, ans);
            }
        }

        return ans;
    }
};