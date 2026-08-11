class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans=0;
        vector<long long> freq(24,0);
        for(int i=0;i<hours.size();i++)
        {
            int rem=hours[i]%24;
            int req=(24-rem)%24;
            if(freq[req]!=0)
            {
                ans+=freq[req];
            }
            freq[rem]++;
        }
        return ans;
    }
};