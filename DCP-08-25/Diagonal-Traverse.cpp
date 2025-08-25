class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        map<int,vector<int>> mp;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for(auto [key,va]:mp)
        {
            if(key%2==0)
            {
                reverse(va.begin(),va.end());
            }
            for(auto i:va)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};