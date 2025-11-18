class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
                int n=grid[0].size();

            vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
           
    vector<int> dy = {0, -1, -1, -1, 0, 1, 1, 1};
        vector<vector<int>> vis(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
         if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 &&nx<n && ny>=0 &&ny<n && grid[nx][ny]==0 && vis[nx][ny]==-1)
                {
                    vis[nx][ny]=vis[x][y]+1;
                    q.push({nx,ny});

                }
            }
        }

return vis[n-1][n-1];
        
    }
};