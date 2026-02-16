class Solution {
public:
int lcs(string &s1,string &s2,vector<vector<int>> &dp,int n,int q)
{
    if(n==0||q==0)
    {
        return dp[n][q]=0;
    }
    if(dp[n][q]!=-1)
    {
        return dp[n][q];
    }
    if(s1[n-1]==s2[q-1])
    {
        return dp[n][q]=1+lcs(s1,s2,dp,n-1,q-1);
    }
    else{
        return dp[n][q]=max(lcs(s1,s2,dp,n-1,q),lcs(s1,s2,dp,n,q-1));
    }
}
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string k=s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return lcs(k,s,dp,n,n);

    }
};