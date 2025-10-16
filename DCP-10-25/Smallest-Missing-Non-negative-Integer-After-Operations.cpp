class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
       
        unordered_map<int,int> mp;
    for(int it:nums)
    {
        int rem=((it%value)+value)%value;
        mp[rem]++;

    }
    int mex;
    for(int i=0;i<value;i++)
    {
        if(mp[i]==0)
        {
            mex=i;
            break;

        }

    }
 int mexi=0;
 while(true)
 {
    int rem=mexi%value;
    if(mp[rem]!=0)
    {
        mp[rem]--;
        mexi++;
    }
    else{
        return mexi;
    }
 }  
return -1;
        
    }
};