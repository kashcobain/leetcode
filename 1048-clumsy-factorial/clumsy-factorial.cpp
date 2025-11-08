class Solution {
public:
    int helper(int n, vector<int> &dp)
    {
        if(n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 6;
        if(n==4)return 6; 

        if(dp[n]!=-1)return dp[n];

        return dp[n] = (n*(n-1))/(n-2) + helper(n-4, dp);
    }

    int clumsy(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 6;
        if(n==4)return 7;

        vector<int> dp(10000, -1);
        int i = n - 3;
        int sum = 0;

        while(i >= 0)  
        {
            sum += i;
            i -= 4;
        }

        return (n*(n-1))/(n-2) - helper(n-4, dp) + sum; 
    }
};
