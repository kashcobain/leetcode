class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int m = heights.size();
        int n = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while (!pq.empty()) {

            auto pr = pq.top();
            pq.pop();

            int dist_of_par = pr[0];
            int x = pr[1];
            int y = pr[2];

            // optimization
            if (x == m - 1 && y == n - 1)
                return dist_of_par;

            for (int k = 0; k < 4; k++) {

                int newx = x + dx[k];
                int newy = y + dy[k];

                if (newx >= 0 && newy >= 0 && newx < m && newy < n) {

                    int new_dist_of_nbr = max(
                        dist_of_par,
                        abs(heights[x][y] - heights[newx][newy])
                    );

                    if (new_dist_of_nbr < dist[newx][newy]) {

                        dist[newx][newy] = new_dist_of_nbr;
                        pq.push({new_dist_of_nbr, newx, newy});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};