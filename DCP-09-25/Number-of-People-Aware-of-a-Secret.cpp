class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod=1e9+7;
        vector<long long> dp(n+1,0);
        dp[1]=1;
        for(int i=1;i<n;i++)
        {

            long long people=dp[i];
            if(people==0)continue;
            for(int shareday=i+delay;shareday<i+forget && shareday<=n;shareday++)
            {
                dp[shareday]=(dp[shareday]+people)%mod;
            }

        }
        int ans=0;
        for(int i=n-forget+1;i<=n;i++)
        {
            if(i>0)
            {
                ans=(ans+dp[i])%mod;
            }
        }
        return ans;

    }
};