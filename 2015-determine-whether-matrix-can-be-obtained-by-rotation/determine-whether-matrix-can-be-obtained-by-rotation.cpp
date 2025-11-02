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
        for(int i=0;i<=3;i++){
            rotate(mat);
            if(mat==target){
                return true;
            }
            else{
                continue;
            }
        }
        return false;
        
        
    }
};