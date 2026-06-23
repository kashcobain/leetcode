class Solution {
public:
    pair<int,int> insertinto(int a,int b)
    {
        if(a>b)
        {
            return {b,a};
        }
        else{
            return {a,b};
        }
    }
    int findPairs(vector<int>& nums, int k) {
      set<pair<int,int>> st;
        unordered_map<int,int> mp;

        vector<int> val;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int count=0;
        if(k==0)
        {
            for(auto it:mp)
            {
                if(it.second>=2)
                {
                    count++;
                }
            }
            return count;
        }
        for(int i=0;i<nums.size();i++)
        {
            int a=nums[i];
            if(mp.find(a+k)!=mp.end() )
            {
                pair<int,int> pr=insertinto(a,a+k);
                if(st.find(pr)==st.end())
                {
                    count++;
                    st.insert(pr);
                }

            }
            
             
        }
        return count;
    }
};