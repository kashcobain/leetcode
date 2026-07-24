class Solution {
public:
   unordered_map<int,bool>rowMap ;
unordered_map<int,bool>left_downMap;
unordered_map<int,bool>left_upMap;

int totalNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board (n,string(n,'.'));
    solve(0,n,board,ans);
    return ans.size();
}

void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans){

    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++){
        if(isValid(row,col,n)){
            // setting in maps
            rowMap[row] = true;
            left_downMap[row+col+n] = true;
            left_upMap[row-col+n] = true;

            // making recursive calls
            board[row][col] = 'Q';
            solve(col+1,n,board,ans);
            board[row][col] = '.';

            // unsetting in maps
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