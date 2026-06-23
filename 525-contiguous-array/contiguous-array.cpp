class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        unordered_map<int,int> mp;
        mp[0]=-1;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                sum+=-1;
            }
            else{
                sum+=1;
            }
            pre[i]=sum;
            if(mp.find(sum)!=mp.end())
            {
                ans=max(ans,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }

        }
        return ans;
    }
};