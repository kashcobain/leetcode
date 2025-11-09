class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();

        vis[i][j]=1;
        int v[]={-1,0,1,0};
        int h[]={0,-1,0,1};
        for(int k=0;k<4;k++)
        {
            int newr=i+v[k];
            int newc=j+h[k];
            if(newr>=0 && newr<m && newc>=0 && newc<n && grid[newr][newc]=='1' && !vis[newr][newc])
            {
                dfs(grid,vis,newr,newc);
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       int count=0;
       vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    dfs(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};