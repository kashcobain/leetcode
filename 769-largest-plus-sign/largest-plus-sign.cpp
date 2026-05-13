class Solution {
public:

    int up(int i,int j,vector<vector<int>> &grid,int n,vector<vector<int>> &dpu)
    {
        
        if(i < 0 || grid[i][j] == 0)
            return 0;
            if(dpu[i][j]!=-1)return dpu[i][j];

        return dpu[i][j]=1 + up(i-1,j,grid,n,dpu);
    }

    int down(int i,int j,vector<vector<int>> &grid,int n,vector<vector<int>> &dpd)
    {
       
        if(i >= n || grid[i][j] == 0)
            return 0;
     if(dpd[i][j]!=-1)return dpd[i][j];
        return dpd[i][j]=1 + down(i+1,j,grid,n,dpd);
    }

    int left(int i,int j,vector<vector<int>> &grid,int n,vector<vector<int>> &dpl)
    {
        
        if(j < 0 || grid[i][j] == 0)
            return 0;
 if(dpl[i][j]!=-1)return dpl[i][j];
        return dpl[i][j]=1 + left(i,j-1,grid,n,dpl);
    }

    int right(int i,int j,vector<vector<int>> &grid,int n,vector<vector<int>> &dpr)
    {
       
        if(j >= n || grid[i][j] == 0)
            return 0;
             if(dpr[i][j]!=-1)return dpr[i][j];

        return dpr[i][j]=1 + right(i,j+1,grid,n,dpr);
    }

    int orderOfLargestPlusSign(int n,
                               vector<vector<int>>& mines) {

        vector<vector<int>> grid(n,
                                 vector<int>(n,1));

       vector<vector<int>> dpu(n,vector<int>(n,-1));
       vector<vector<int>> dpd(n,vector<int>(n,-1));
       vector<vector<int>> dpl(n,vector<int>(n,-1));
       vector<vector<int>> dpr(n,vector<int>(n,-1));
        for(auto &it : mines)
        {
            grid[it[0]][it[1]] = 0;
        }

        int maxi = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    int u = up(i,j,grid,n,dpu);
                    int d = down(i,j,grid,n,dpd);
                    int l = left(i,j,grid,n,dpl);
                    int r = right(i,j,grid,n,dpr);

                    int ans = min({u,d,l,r});

                    maxi = max(maxi,ans);
                }
            }
        }

        return maxi;
    }
};