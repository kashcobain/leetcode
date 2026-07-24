class Solution {
public:
   unordered_map<int,bool>rowMap ;
unordered_map<int,bool>left_downMap;
unordered_map<int,bool>left_upMap;

int totalNQueens(int n) {
    int ans=0;
    vector<string> board (n,string(n,'.'));
    solve(0,n,board,ans);
    return ans;
}

void solve(int col, int n, vector<string>& board, int &ans){

    if(col==n){
       ans++;
        return;
    }

    for(int row = 0; row < n; row++){
        if(isValid(row,col,n)){
          
            rowMap[row] = true;
            left_downMap[row+col+n] = true;
            left_upMap[row-col+n] = true;

          
            board[row][col] = 'Q';
            solve(col+1,n,board,ans);
            board[row][col] = '.';

           
            rowMap[row] = false;
            left_downMap[row+col+n] = false;
            left_upMap[row-col+n] = false;
        }
    }
}

bool isValid(int row, int col, int n){
    
    bool cnd1 = rowMap[row];
    bool cnd2 = left_upMap[row-col+n];
    bool cnd3 = left_downMap[row+col+n];

    return (cnd1 || cnd2 || cnd3)? false:true;
}
};