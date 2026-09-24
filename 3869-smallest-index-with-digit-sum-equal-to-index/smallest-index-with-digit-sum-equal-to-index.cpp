class Solution {
public:
    int sum1(int i)
    {
        int ans=0;
        while(i>0)
        {
            ans+=i%10;
            i=i/10;

        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(sum1(nums[i])==i)return i;
        }
        return -1;
    }
};