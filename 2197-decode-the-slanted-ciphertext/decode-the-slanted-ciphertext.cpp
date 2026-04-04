class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        int cols=n/rows;
        vector<vector<char>> mat(rows,vector<char>(cols));
        int idx=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                mat[i][j]=encodedText[idx++];

            }
        }
        string ans="";
        for(int i=0;i<cols;i++)
        {
            int k=0,j=i;
            while(k<rows &&j<cols)
            {
                ans+=mat[k][j];
                k++;
                j++;
            }
        }
        while(!ans.empty() && ans.back()==' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};