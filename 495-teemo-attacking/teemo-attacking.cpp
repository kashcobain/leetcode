class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int duration) {
        int n=time.size();
        int cnt=0;
        
        for(int i=0;i<n-1;i++)
        {
            int diff=time[i+1]-time[i];
            cnt+=min(diff,duration);
        }
        return cnt+duration;
    }
};