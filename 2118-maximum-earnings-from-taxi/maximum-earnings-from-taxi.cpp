
class Solution {
public:
    struct cmp{
        bool operator()(vector<int> &a,vector<int> &b)
        {
            if(a[0]!=b[0])
            {
                return a[0]<b[0];
            }
            else{
                return a[1]<b[1];
            }
        }
    };

    long long solve(int n,int i,vector<vector<int>>& rides,vector<long long> &dp)
    {
        if(i>=n)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        long long nottake=solve(n,i+1,rides,dp);

        int start=rides[i][0];

        int low=i+1;
        int high=n-1;
        int ans=n;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(rides[mid][0]>=rides[i][1])
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }

        long long take=rides[i][1]-rides[i][0]+rides[i][2]
                       +solve(n,ans,rides,dp);

        dp[i]=max(take,nottake);

        return dp[i];
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        sort(rides.begin(),rides.end(),cmp());

        int m=rides.size();

        vector<long long> dp(m,-1);

        return solve(m,0,rides,dp);
    }
};
