class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int mod=12345;
        vector<vector<int>> pre(m,vector<int>(n,0));
        vector<vector<int>> suff(m,vector<int>(n,0));
        long long p=1;
        vector<vector<int>> ans(m,vector<int>(n,0));

        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                pre[i][j]=p;
    p*=grid[i][j];
    p=p%mod;
            }
        }
         p=1;

        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                suff[i][j]=p;
    p*=grid[i][j];
    p=p%mod;
            }
        }
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        ans[i][j]=pre[i][j]*suff[i][j];
        ans[i][j]%=mod;
        
    }
}
        return ans;
    }
};