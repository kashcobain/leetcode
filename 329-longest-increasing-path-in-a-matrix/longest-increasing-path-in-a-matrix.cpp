class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> mat;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int dfs(int i, int j) {

        if (dp[i][j] != -1) 
            return dp[i][j];

        int best = 1;

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n &&
                mat[x][y] > mat[i][j]) 
            {
                best = max(best, 1 + dfs(x, y));
            }
        }

        dp[i][j] = best;
        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        mat = matrix;
        m = mat.size();
        n = mat[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j));
            }
        }

        return ans;
    }
};
