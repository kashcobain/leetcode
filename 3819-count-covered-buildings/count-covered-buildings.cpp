class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,set<int>> mpx;
        unordered_map<int,set<int>> mpy;
        for(auto it:buildings)
        {
            mpx[it[0]].insert(it[1]);
            mpy[it[1]].insert(it[0]);
            
        }
        int ans=0;
        for(auto it:buildings)
        {
            int x=mpx[it[0]].size();
            int y=mpy[it[1]].size();
            if(x<=2 || y<=2)continue;
            if(*mpx[it[0]].begin()==it[1]||*mpx[it[0]].rbegin()==it[1])continue;
            if(*mpy[it[1]].begin()==it[0]||*mpy[it[1]].rbegin()==it[0])continue;
            ans++;

        }

        return ans;
    }
};