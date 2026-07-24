class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        unordered_set<int> st(nums.begin(),nums.end());
        unordered_set<int> st2;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               

                    int xorval;
                    xorval=nums[i]^nums[j];
                    st2.insert(xorval);
                   
                }
            
        }
        for(auto it:nums)
        {
            for(auto kt:st2)
            {
                if(st.find(kt^it)==st.end())
                {
                    st.insert(kt^it);
                }
            }
        }
        return st.size();
    }
};