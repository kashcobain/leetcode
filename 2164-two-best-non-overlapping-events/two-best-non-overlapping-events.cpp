class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        vector<pair<pair<int,int>,int>> vp(2*n);
        for(int i=0;i<n;i++)
        {
            vp[2*i]={{events[i][0],0},events[i][2]};
            vp[2*i+1]={{events[i][1],1},events[i][2]};
        }
        sort(vp.begin(),vp.end());
        int ans=0;
        int mx=0;
        for(auto it:vp)
        {
            if(it.first.second==1)
            {
                mx=max(it.second,mx);
            }
            else{
                ans=max(ans,mx+it.second);
            }
        }
        return ans;
    }
};