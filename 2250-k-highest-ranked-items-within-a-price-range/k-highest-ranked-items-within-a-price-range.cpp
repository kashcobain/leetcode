class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> ans;

        int m=grid.size();
        int n=grid[0].size();
        int dy[]={-1,0,1,0};
        int dx[]={0,1,0,-1};
        pq.push({0,grid[start[0]][start[1]],start[0],start[1]});
        grid[start[0]][start[1]]=0;

        while(!pq.empty() && ans.size()<k)
        {
            auto curr=pq.top();
            pq.pop();
            int dist=curr[0];
            int val=curr[1];
            int x=curr[2];
            int y=curr[3];
            if(val>=pricing[0] && val<=pricing[1])ans.push_back({x,y});
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=0)
                {
                    pq.push({dist+1,grid[nx][ny],nx,ny});
                    grid[nx][ny]=0;
                }
            }
        }
        return ans;
        
    }
};