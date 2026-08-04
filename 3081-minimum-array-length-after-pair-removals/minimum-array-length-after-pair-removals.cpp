class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int maxi=0;
        for(auto it:mp)
        {
            maxi=max(maxi,it.second);
        }
        if(maxi<=n/2)
        {
            if(n%2==0)
            {
                return 0;
            }
            else{
                return 1;
            }
            
        }
        return 2*maxi-n;


        
    }
};