class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prevrow;
        for(int i=0;i<numRows;i++)
        {
            vector<int> currow(i+1,1);
            for(int j=1;j<i;j++)
            {
                currow[j]=prevrow[j]+prevrow[j-1];
            }
            ans.push_back(currow);
            prevrow=currow;


        }
        return ans;
    }
};