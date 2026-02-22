class Solution {
public:


    bool dfs(int curNode,
             vector<bool>& visited,
             vector<bool>& safe,
             vector<vector<int>>& graph)
    {
        visited[curNode] = true;

        bool isSafe = true;

        for (auto nextNode : graph[curNode]) {

            if (!visited[nextNode]) {
                isSafe &= dfs(nextNode, visited, safe, graph);
            }
            
            else if (!safe[nextNode]) {
                isSafe = false;
                break;
            }
        }

        return safe[curNode] = isSafe;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> ans;

        vector<bool> visited(n, false);
        vector<bool> safe(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, safe, graph);
            }
        }

        for (int i = 0; i < n; i++) {
            if (safe[i])
                ans.push_back(i);
        }

        return ans;
    }
};