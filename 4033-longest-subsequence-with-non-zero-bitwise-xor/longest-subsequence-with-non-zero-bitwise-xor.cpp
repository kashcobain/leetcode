class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool allzero=true;
        int xori=0;
        for(auto it:nums)
        {
            xori=xori^it;
            if(it!=0)
            {
                allzero=false;
            }
        }
        if(allzero)
        {
            return 0;
        }
        if(xori==0)
        {
            return n-1;
        }
        else{
            return n;
            
        }
    }
};