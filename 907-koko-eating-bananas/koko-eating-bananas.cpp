class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
       int ans=high;
    
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long val=0;
            for(int i=0;i<n;i++)
            {
val += ceil((double)piles[i] / mid);
            }
            if(val>h)
            {
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
               
            }

        }
        return ans;
        
    }
};