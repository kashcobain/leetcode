class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n=nums.size();
       
         vector<int> pre(n,0);
        pre[0]=nums[0];

         for(int i=1;i<n;i++)
         {
            pre[i]=pre[i-1]+nums[i];
         }
         vector<int> ans(n,0);
         for(int i=0;i<n;i++)
         {
            int leftsum=pre[i]-nums[i];
            int rightsum=pre[n-1]-pre[i];
            int leftcount=i;
            int rightcount=n-1-i;
            int leftt=leftcount*nums[i]-leftsum;
            int rightt=rightsum-rightcount*nums[i];
            ans[i]=leftt+rightt;

         }
         return ans;
    }
};