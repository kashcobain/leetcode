class Solution {
public:
     vector<vector<int>> rotate(vector<vector<int>> & matrix)
     {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
       
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return matrix;
     }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> mat1=rotate(mat);
        vector<vector<int>> mat2=rotate(mat);
        vector<vector<int>> mat3=rotate(mat);
        vector<vector<int>> mat4=rotate(mat);
        if(target==mat1 || target==mat2 || target==mat3 || target==mat4)
        {
            return true;
        }
        return false;
        
        
    }
};