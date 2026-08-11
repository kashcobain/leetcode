class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        vector<int> freq(24, 0);
        int ans = 0;

        

        for(int i = 0; i < hours.size(); i++)
        {
            
            int rem=hours[i]%24;
            int req=(24-rem)%24;
            if(freq[req])
            {
                ans+=freq[req];
            }
            freq[rem]++;
        }
        return ans;
    }
};