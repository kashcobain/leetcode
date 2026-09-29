class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       
        stack<int> st;
        for(auto it:nums)
        {
            st.push(it);

        }
        int ans=0;
        unordered_map<int,int> mp;
        while(!st.empty())
        {
            int num=st.top();
            if(num<=k)
            {
                mp[num]++;
            }
            ans++;
            st.pop();
            if(mp.size()==k)return ans;
        }
        return ans;
    }
};