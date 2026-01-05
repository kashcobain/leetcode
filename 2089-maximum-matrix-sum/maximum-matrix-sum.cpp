class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int mini = INT_MAX;
        int count = 0;
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) {
                    count++;               
                }
                ans += abs(matrix[i][j]);  
                mini = min(mini, abs(matrix[i][j])); 
            }
        }

        
        if (count % 2 != 0) {
            ans -= 2 * mini;
        }

        return ans;
    }
};
