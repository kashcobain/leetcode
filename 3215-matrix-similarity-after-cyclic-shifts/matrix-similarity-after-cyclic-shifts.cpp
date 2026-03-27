class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> old = mat;
        int z = k % m;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                
                reverse(mat[i].begin(), mat[i].begin() + z);
                reverse(mat[i].begin() + z, mat[i].end());
                reverse(mat[i].begin(), mat[i].end());
            } else {
            reverse(mat[i].begin(), mat[i].end() - z);
                reverse(mat[i].end() - z, mat[i].end());
                reverse(mat[i].begin(), mat[i].end());
            }
        }

        return mat == old;
    }
};