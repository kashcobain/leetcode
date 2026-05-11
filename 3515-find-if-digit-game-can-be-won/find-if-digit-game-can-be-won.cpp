class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1=0;
        int sum2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<10)
            {
                sum1+=nums[i];
            }
            else{
                sum2+=nums[i];
            }
        }
        int ali=(sum1>sum2?sum1:sum2);
        int bob=sum1+sum2-ali;
        return (ali>bob);

        
    }
};