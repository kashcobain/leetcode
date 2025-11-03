class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0;
        int prev=neededTime[0];
        for(int i=0;i<n-1;i++)
        {
            if(colors[i]==colors[i+1])
            {
                ans+=min(prev,neededTime[i+1]);
                prev=max(prev,neededTime[i+1]);

            }
            else{
                prev=neededTime[i+1];
            }
        }
        return ans;
    }
};