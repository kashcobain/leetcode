class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));

        for(int i=0;i+k<=m;i++){
            for(int j=0;j+k<=n;j++){

                set<int> st; // FIXED

                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        st.insert(grid[x][y]);
                    }
                }

                if(st.size() <= 1){
                    ans[i][j] = 0;
                }
                else{
                    int mn = INT_MAX;

                    auto it = st.begin();
                    auto prev = it;
                    it++;

                    while(it != st.end()){
                        mn = min(mn, *it - *prev);
                        prev = it;
                        it++;
                    }

                    ans[i][j] = mn; 
                }
            }
        }

        return ans;
    }
};