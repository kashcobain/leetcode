class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<vector<int>> count1,count2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]==1)
                {
                    count1.push_back({i,j});
                }
                if(img2[i][j]==1)
                {
                    count2.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int> mp;
        int ans=0;

        for(auto it1:count1)
        {
            for(auto it2:count2)
            {
                int a1=it1[0];
                int a2=it1[1];
                int b1=it2[0];
                int b2=it2[1];
                mp[{(a1-b1),(a2-b2)}]++;
                ans=max(ans, mp[{(a1-b1),(a2-b2)}]);
                
            }
        }
        return ans;
    }
};