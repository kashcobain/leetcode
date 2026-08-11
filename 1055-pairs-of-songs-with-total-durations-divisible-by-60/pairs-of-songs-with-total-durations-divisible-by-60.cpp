class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        vector<int> freq(60,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int rem=time[i]%60;
            int req=(60-rem)%60;
            if(freq[req]!=0)
            {
                ans+=freq[req];
            }
            freq[rem]++;
        }
        return ans;
        
    }
};