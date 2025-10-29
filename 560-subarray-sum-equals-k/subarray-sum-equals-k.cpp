class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int count=0;
        int cursum=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            cursum+=nums[i];
            if(mp.find(cursum-k)!=mp.end())
            {
                count+=mp[cursum-k];
            }
            mp[cursum]++;
        }
        return count;

    }
};