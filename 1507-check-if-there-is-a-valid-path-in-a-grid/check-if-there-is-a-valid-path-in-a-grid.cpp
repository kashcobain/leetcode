class Solution {
public:
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<pair<int,int>>> dir(7);
       dir[1]={{0,-1},{0,1}};
       dir[2]={{-1,0},{1,0}};
       dir[3]={{0,-1},{1,0}};
       dir[4]={{0,1},{1,0}};
       dir[5]={{0,-1},{-1,0}};
       dir[6]={{0,1},{-1,0}};
       queue<pair<int,int>> q;
       vector<vector<int>> vis(n,vector<int>(m,0));
       q.push({0,0});
       vis[0][0]=1;
       while(!q.empty())
       {
        auto node=q.front();
        q.pop();
        if(node.first==n-1 && node.second==m-1)
        {
            return true;
        }
        int r=node.first;
        int c=node.second;
        for(auto [dr,dc]:dir[grid[r][c]])
        {
            int nr=r+dr;
            int nc=c+dc;
            if(nr<0 || nc<0 || nr>=n ||nc>=m ||vis[nr][nc] )
            {
                continue;
            }
            for(auto [bdr,bdc]:dir[grid[nr][nc]])
            {
                if(nr+bdr==r && nc+bdc==c)
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }

        }





       }
        return false;
        
    }
};