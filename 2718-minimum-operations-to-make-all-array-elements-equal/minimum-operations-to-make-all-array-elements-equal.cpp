#define ll long long int
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        sort(nums.begin(),nums.end());
        vector<ll> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+nums[i]*1ll;

        vector<ll> ans;
        for(int q:queries)
        {
            auto it = upper_bound(nums.begin(), nums.end(), q);
            int i = (it == nums.begin()) ? -1 : (it - nums.begin() - 1);
            long long x=(i<0)?0:(1ll*(i+1)*q-pre[i]);
            long long y=(i<0)?(pre[n-1]-1ll*n*q):(-1ll*(n-i-1)*q+pre[n-1]-pre[i]);


            ans.push_back(x+y);

        }

        return ans;
    }
};