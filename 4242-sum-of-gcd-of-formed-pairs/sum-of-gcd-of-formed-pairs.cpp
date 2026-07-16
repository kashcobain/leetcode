class Solution {
public:
    long long gcdSum(vector<int>& nums) {
       int n=nums.size();
       if(n==0)return 0;
       vector<int> ans;
       int maxi=INT_MIN;
       for(int i=0;i<n;i++)
       {
        maxi=max(maxi,nums[i]);
        ans.push_back(gcd(maxi,nums[i]));

       }
       sort(ans.begin(),ans.end());
       long long sum=0;
       for(int i=0;i<n/2;i++)
       {
        sum+=1LL*gcd(ans[i],ans[n-i-1]);
       }
       return sum;
        
    }
};