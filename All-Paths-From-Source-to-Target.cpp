class Solution {
public:
void dfs(int node,vector<int> &path,vector<vector<int>> &ans,vector<vector<int>> & graph)
{
    int n=graph.size();
    path.push_back(node);
    for(auto it:graph[node])
    {
        dfs(it,path,ans,graph);
    }
    if(node==n-1){
        ans.push_back(path);
    }
    path.pop_back();

}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> path;
        vector<vector<int>> ans;
        dfs(0,path,ans,graph);
        return ans;
        
    }
};