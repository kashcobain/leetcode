class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        int precnt=0;
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                cnt++;
            }
            else{
                precnt=cnt;
                cnt=1;
            }
            ans=max(ans,min(cnt,precnt));
            ans=max(ans,cnt/2);

        }
        return ans;
    }
};