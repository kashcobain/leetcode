class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> pref(n+1, vector<long long>(m+1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                pref[i][j] = grid[i-1][j-1]
                           + pref[i-1][j]
                           + pref[i][j-1]
                           - pref[i-1][j-1];
            }
        }

        long long total = pref[n][m];
        if(total % 2) return false;

        long long half = total / 2;

        for(int i = 0; i < n-1; i++) {
            long long top = pref[i+1][m];
            if(top == half) return true;
        }

        for(int j = 0; j < m-1; j++) {
            long long left = pref[n][j+1];
            if(left == half) return true;
        }

        return false;
    }
};