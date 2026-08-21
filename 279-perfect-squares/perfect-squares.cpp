class Solution {
public:
   int solve(int i, vector<vector<int>>& dp, vector<int>& per, int n)
{
    if(n == 0)
        return 0;

    if(i < 0)
        return INT_MAX;

    if(dp[i][n] != -1)
        return dp[i][n];

    int take = INT_MAX;

    if(per[i] <= n)
    {
        int x = solve(i, dp, per, n - per[i]);

        if(x != INT_MAX)
            take = 1 + x;
    }

    int notTake = solve(i - 1, dp, per, n);

    return dp[i][n] = min(take, notTake);
}
    int numSquares(int n) {
        vector<int> per;
        for(int i=1;i*i<=n;i++)
        {
            per.push_back(i*i);

        }
        vector<vector<int>> dp(per.size()+1,vector<int>(n+1,-1));
        return solve(per.size()-1,dp,per,n);

        
    }
};