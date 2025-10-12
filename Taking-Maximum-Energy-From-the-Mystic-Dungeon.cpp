class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=INT_MIN;
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=energy[i];
            if(i<n-k)dp[i]+=dp[i+k];
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};