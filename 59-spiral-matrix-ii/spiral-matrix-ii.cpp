class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> mat(n, vector<int>(n));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        int count = 1;

        while (top <= bottom && left <= right) {

           
            for (int i = left; i <= right; i++) {
                mat[top][i] = count++;
            }
            top++;

         
            for (int i = top; i <= bottom; i++) {
                mat[i][right] = count++;
            }
            right--;


            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    mat[bottom][i] = count++;
                }
                bottom--;
            }

           
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    mat[i][left] = count++;
                }
                left++;
            }
        }

        return mat;
    }
};