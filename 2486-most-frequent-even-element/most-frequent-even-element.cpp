class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
           { mp[nums[i]]++;}
        }
    
        int maxi=INT_MIN;
        for(auto it:mp)
        {
            if(it.second>maxi)
            {
                maxi=it.second;
            }

        }
        int num=INT_MAX;
        for(auto it:mp)
        {
            if(it.second==maxi)
            {
                if(num>=it.first)
                {
                    num=it.first;
                }

            }
        }
        if(num==INT_MAX)return -1;
        return num;
    }
};