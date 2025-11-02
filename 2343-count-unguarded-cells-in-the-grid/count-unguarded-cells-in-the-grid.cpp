class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        int a=guards.size();
        int b=walls.size();

        for(int i=0;i<a;i++)
        {
            int row=guards[i][0];
            int col=guards[i][1];
            matrix[row][col]=0;
        }
        for(int i=0;i<b;i++)
        {
            int row=walls[i][0];
            int col=walls[i][1];
            matrix[row][col]=1;
        }
        int i=0;
        int j=0;
      vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        

       for(int i=0;i<m;i++)
       {

       for(int j=0;j<n;j++)
        {
                if(matrix[i][j]==0)
                {
                        for(int k=0;k<4;k++)
                        {
                            int newr=i+directions[k].first;
                            int newc=j+directions[k].second;
                            while(newr>=0 && newr<m && newc>=0 && newc<n)
                            {
                                if(matrix[newr][newc]==0 || matrix[newr][newc]==1 )
                                {
                                    break;
                                }
                                if(matrix[newr][newc]==-1){
                                    matrix[newr][newc]=2;
                                }
                                newr+=directions[k].first;
                                newc+=directions[k].second;
                            }
                        }
                }

            
        }
       }
        int count=0;
        for(int c=0;c<m;c++)
        {
            for(int d=0;d<n;d++)
            {
                if(matrix[c][d]==-1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};