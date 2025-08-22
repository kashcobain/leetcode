class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int top = m, bottom = -1, leftmost = n, rightmost = -1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    top = min(top, i);
                    bottom = max(bottom, i);
                    leftmost = min(leftmost, j);
                    rightmost = max(rightmost, j);
                }
            }
        }

        if (bottom == -1) return 0;

        return (bottom - top + 1) * (rightmost - leftmost + 1);
    }
};
