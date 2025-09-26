class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        for(int j=n-1;j>=2;j--)
        {
        int i=0,k=j-1;
        while(i<k)
        {
            if(nums[i]+nums[k]>nums[j])
            {
                count+=k-i;
                k--;
            }
            else{
                i++;
            }
        }
        }
      
        return count;
    }
};