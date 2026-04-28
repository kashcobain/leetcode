class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> ele;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ele.push_back(grid[i][j]);
            }
        }
        sort(ele.begin(),ele.end());
        int k=ele.size();
        int median=ele[k/2];
        int result=0;
        for(int num:ele)
        {
            if(num%x!=median%x)return -1;
            result+=abs(median-num)/x;
        }
        return result;


        
    }
};