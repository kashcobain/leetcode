class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        vector<long long> dp(n,0);
        long long ans=1;
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(prices[i]==prices[i-1]-1)
            {
                dp[i]=dp[i-1]+1;
            }
            else{
                dp[i]=1;
            }
            ans+=dp[i];
        }
        return ans;
    }
};