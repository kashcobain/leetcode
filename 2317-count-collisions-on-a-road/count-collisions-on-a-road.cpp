class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        int l=0;
        int r=n-1;
        int count=0;
        while(l<n &&directions[l]=='L')l++;
        while(r>=0 &&directions[r]=='R')r--;
        for(int i=l;i<=r;i++)
        {
            if(directions[i]!='S')
            {
                count++;
            }
        }
return count;
        
    }
};