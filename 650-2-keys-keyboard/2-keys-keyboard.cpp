class Solution {
public:

    int minSteps(int n) {
        if(n==1)return 0;
        vector<vector<int>> dp(n+1,vector<int>(n/2+1,-1));
        return 1+minhelper(1,1,dp,n);
        
    }
    int minhelper(int curlen,int pastlen,vector<vector<int>> &dp,int n)
    {
        if(curlen==n)return 0;
        if(curlen>n)return 1000;
        if(dp[curlen][pastlen]!=-1)return dp[curlen][pastlen];
        int op1=1+minhelper(curlen+pastlen,pastlen,dp,n);
        int op2=2+minhelper(curlen*2,curlen,dp,n);
        dp[curlen][pastlen]=min(op1,op2);
        return dp[curlen][pastlen];
    }
};