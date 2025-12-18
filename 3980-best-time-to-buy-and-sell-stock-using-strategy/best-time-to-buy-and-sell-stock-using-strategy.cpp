class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        int half=k/2;
        long long base=0;
        vector<long long> a(n),b(n);
        for(int i=0;i<n;i++)
        {
            a[i]=1LL*strategy[i]*prices[i];
            b[i]=prices[i]-a[i];
            base+=prices[i]*strategy[i];
        }
        vector<long long> prea(n+1,0),preb(n+1,0);
        for(int i=0;i<n;i++)
        {
            prea[i+1]=prea[i]+a[i];
            preb[i+1]=preb[i]+b[i];
        }
        long long ans=0;
        for(int  i=0;i+k<=n;i++)
        {
            long long firsthalf=prea[i+half]-prea[i];
            long long secondhalf=preb[i+k]-preb[i+half];
            long long delta=-firsthalf+secondhalf;
            ans=max(ans,delta);
        }
        return base+ans;
    }
};