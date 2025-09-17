class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int k = numCourses;

        // Step 1: Create adjacency list
        vector<int> adj[k];
        for (auto& it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a); // edge: b → a
        }

        // Step 2: Calculate indegrees
        vector<int> indegree(k, 0);
        for (int i = 0; i < k; i++) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }

        // Step 3: Push all 0-indegree nodes into the queue
        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Step 4: Kahn's algorithm
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Step 5: Return the result
        if (ans.size() == k)
            return ans;
        else
            return {};
    }
};