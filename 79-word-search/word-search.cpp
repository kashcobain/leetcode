class Solution {
public:
    bool flag=false;
    void solve(int i,int j,int len,vector<vector<char>>& board, string word)
    {
         int n=board.size();
        int m=board[0].size();
        if(len==word.size())
        {
            flag=true;
            return ;
        }
        if(j-1>=0 && board[i][j-1]==word[len])
        {
            board[i][j-1]='!';
            solve(i,j-1,len+1,board,word);
            board[i][j-1]=word[len];
        }
        if(j+1<m && board[i][j+1]==word[len])
        {
            board[i][j+1]='!';
            solve(i,j+1,len+1,board,word);
            board[i][j+1]=word[len];
        }
        if(i-1>=0 && board[i-1][j]==word[len])
        {
            board[i-1][j]='!';
            solve(i-1,j,len+1,board,word);
            board[i-1][j]=word[len];
        }
        if(i+1<n && board[i+1][j]==word[len])
        {
            board[i+1][j]='!';
            solve(i+1,j,len+1,board,word);
            board[i+1][j]=word[len];
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    board[i][j]='!';
                    solve(i,j,1,board,word);
                    board[i][j]=word[0];
                    if(flag)return true;
                }
            }
        }
return false;
    }
};