class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        if(q.empty()||q.size()==n*n)return -1;

        int dist=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty())
        {
            int k=q.size();
            dist++;
            for(int i=0;i<k;i++)
            {
                int curdist=0;
               auto node=q.front();
                q.pop();
                int x=node.first;
                int y=node.second;
                for(int i=0;i<4;i++)
                {
                    int newx=x+dx[i];
                    int newy=y+dy[i];
                    if(newx>=0 && newx<n && newy>=0 && newy<n && grid[newx][newy]==0)
                    {
                      grid[newx][newy]=1;
                      q.push({newx,newy});
                    }
                    
                }
            }
        }

return dist-1;

        
    }
};