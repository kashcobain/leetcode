class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0){
                    dp[0][0]=grid[0][0];
                    continue;
                }
                int left=1e9;
                int down=1e9;

                if(i-1>=0)left=grid[i][j]+dp[i-1][j];
                if(j-1>=0)down=grid[i][j]+dp[i][j-1];
                dp[i][j]=min(left,down);
            }

        }
return dp[n-1][m-1];
        
    }
};