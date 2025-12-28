class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
    int n=grid[0].size();
    long long ans=0;
    int r=0;
    int c=n-1;
    while(r<m && c>=0)
    {
        if(grid[r][c]<0)
        {
            ans+=m-r;
            c--;
        }
        else{
            r++;
        }
    }
        return ans;
    }
};