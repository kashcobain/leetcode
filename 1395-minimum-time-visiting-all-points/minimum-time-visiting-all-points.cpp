class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            int curx=points[i][0];
            int cury=points[i][1];
            int nextx=points[i+1][0];
            int nexty=points[i+1][1];
            ans+=max(abs(nextx-curx),abs(nexty-cury));
        }
        return ans;
    }
};