class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        set<long long> st;
        for(int i=0;i<n;i++)
        {
            long long num=nums[i];
            auto it=st.lower_bound(num-(long long)valueDiff);
    if(it!=st.end() && *it<=num+(long long)valueDiff)
    {
        return true;
    }
    st.insert(nums[i]);
    if(i>=indexDiff)
        {
            st.erase(nums[i-indexDiff]);
        }
        }
        return false;
        
    }
};