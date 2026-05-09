class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int layers=min(m,n)/2;
        for(int layer=0;layer<layers;layer++)
        {
            vector<int> elements;
            int top=layer;
            int bottom=n-layer-1;
            int left=layer;
            int right=m-layer-1;
            for(int i=left;i<=right;i++)
            {
                elements.push_back(grid[top][i]);
            }
            for(int i=top+1;i<=bottom-1;i++ )
            {
                elements.push_back(grid[i][right]);
            }
            for(int i=right;i>=left;i--)
            {
                elements.push_back(grid[bottom][i]);
            }
            for(int i=bottom-1;i>=top+1;i-- )
            {
                elements.push_back(grid[i][left]);
            }
            int size=elements.size();
            int rotateind=k%size;
            int ind=rotateind;
            for(int i=left;i<=right;i++)
            {
                grid[top][i]=elements[ind];
                ind++;
                if(ind==size)
                {
                    ind=0;
                }
            }
            for(int i=top+1;i<=bottom-1;i++ )
            {
               grid[i][right]=elements[ind];
               ind++;
               if(ind==size)
                {
                    ind=0;
                }

            }
            for(int i=right;i>=left;i--)
            {
                grid[bottom][i]=elements[ind];
                ind++;
                if(ind==size)
                {
                    ind=0;
                }
            }
            for(int i=bottom-1;i>=top+1;i-- )
            {
                grid[i][left]=elements[ind];
                ind++;
                if(ind==size)
                {
                    ind=0;
                }
            }


        }
        return grid;
    }
};