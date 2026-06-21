class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        int ini=0;
        for(int i=0;i<costs.size();i++)
        {
            if(ini+costs[i]<=coins)
            {
                ans++;
                ini=ini+costs[i];
            }
         if(ini>coins)
            {
                break;

            }
        }
        return ans;
    }
};