class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;

        }
        int ans=0;
        if(mp[1]%2==0)
        {
            ans=mp[1]-1;
        }
        else{
            ans=mp[1];
        }
        mp.erase(1);
        for(auto &it:mp)
        {
            int res=0;
            long long x=it.first;
            for(;mp.find(x)!=mp.end() && mp[x]>1;x=x*x)
            {
                res+=2;
            }
            int val;
            if(mp.find(x)!=mp.end())
            {
                val=1;
            }
            else{
                val=-1;
            }
ans=max(ans,res+val);

        }
return ans;


        
    }
};