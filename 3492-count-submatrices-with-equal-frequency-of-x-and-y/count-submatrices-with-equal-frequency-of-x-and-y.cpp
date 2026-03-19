class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
        vector<vector<int>> cntX(m+1, vector<int>(n+1, 0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                int val = 0;
                if(grid[i][j]=='X') val = 1;
                else if(grid[i][j]=='Y') val = -1;

                sum[i+1][j+1] = val 
                              + sum[i][j+1] 
                              + sum[i+1][j] 
                              - sum[i][j];

                // prefix count of X
                int isX = (grid[i][j]=='X');
                cntX[i+1][j+1] = isX 
                               + cntX[i][j+1] 
                               + cntX[i+1][j] 
                               - cntX[i][j];
            }
        }

        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int total = sum[i+1][j+1];
                int xCount = cntX[i+1][j+1];

                if(total == 0 && xCount > 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};