class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> temp(n, vector<int>(m));
        vector<int> arr;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                arr.push_back(grid[i][j]);
            }
        }

        int sz = arr.size();
        k %= sz;

        
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());

        int p = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                temp[i][j] = arr[p++];
            }
        }

        return temp;
    }
};