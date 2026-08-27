class Solution {
public:
    bool ifpos(int mid,vector<int>& position, int m)
    {
        int balls=1;
        int start=0;
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-position[start]>=mid)
            {
                balls++;
                start=i;
            }
        }
if(balls>=m)
{
    return true;
}
else {
    return false;
}
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1,high=position[n-1]-position[0];
        int ans=-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(ifpos(mid,position,m))
            {
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;

            }

        }
        return ans;
    }
};