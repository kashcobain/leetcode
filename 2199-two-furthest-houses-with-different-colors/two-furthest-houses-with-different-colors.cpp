class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j)
        {
            if(colors[i]!=colors[j])
            {
                ans=max(ans,j-i);
                i++;
                j=n-1;
            }
            else{
                j--;
            }
        }
        return ans;
        
    }
};