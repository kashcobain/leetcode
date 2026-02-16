class Solution {
public:
int lcs(string word1, string word2,vector<vector<int>> &dp,int m,int n)
{
    if(m==0||n==0)
    {
        return dp[m][n]=0;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    if(word1[m-1]==word2[n-1])
    {
        return dp[m][n]=1+lcs(word1,word2,dp,m-1,n-1);
    }
    else{
        return dp[m][n]=max(lcs(word1,word2,dp,m-1,n),lcs(word1,word2,dp,m,n-1));
    }
}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int common=lcs(word1,word2,dp,m,n);
        int unc=m-common;
        int remaining=n-common;
        return unc+remaining;
        
    }
};