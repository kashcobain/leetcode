class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int k = numCourses;
        vector<int> adj[k];

        
        for (auto it : pre) {
            int a = it[0]; // course
            int b = it[1]; // prerequisite
            adj[b].push_back(a); // edge from b -> a
        }

        // Step 2: Compute indegrees
        vector<int> indegree(k, 0);
        for (int i = 0; i < k; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Step 3: Add nodes with indegree 0 to queue
        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Step 4: BFS for topological sort
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo.size() == k;
    }
};