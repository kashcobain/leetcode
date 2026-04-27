class Solution {
public:
    int f(int i,int j,vector<int>& cuts, vector<vector<int>> &dp)
    {
        if(i>j)return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        for(int k=i;k<=j;k++)
        {
            int cost=cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            mini=min(mini,cost);


        }
        return dp[i][j]=mini;

    }
    int minCost(int n, vector<int>& cuts) {
        int k=cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(k+1,vector<int>(k+1,-1));


        return f(1,k,cuts,dp);

        
        
    }
};