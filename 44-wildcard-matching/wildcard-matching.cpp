class Solution {
public:
    bool lcs(string &s1,string &s2,vector<vector<int>> &dp,int m,int n)
    {
        if(n==0) return m==0;

        if(dp[m][n]!=-1)
            return dp[m][n];

        if(m==0)
        {
            for(int i=0;i<n;i++)
            {
                if(s2[i]!='*')
                    return dp[m][n]=false;
            }
            return dp[m][n]=true;
        }

        if(s1[m-1]==s2[n-1] || s2[n-1]=='?')
            return dp[m][n]=lcs(s1,s2,dp,m-1,n-1);

        if(s2[n-1]=='*')
            return dp[m][n]=
                lcs(s1,s2,dp,m-1,n) ||   
                lcs(s1,s2,dp,m,n-1);     

        return dp[m][n]=false;
    }

    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return lcs(s,p,dp,m,n);
    }
};
