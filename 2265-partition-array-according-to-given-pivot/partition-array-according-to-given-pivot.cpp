class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> bef;
        vector<int> aft;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
            {
                bef.push_back(nums[i]);
            }
            if(nums[i]>pivot)
            {
                aft.push_back(nums[i]);
            }
        }
        int same=n-bef.size()-aft.size();
    for(int i=0;i<bef.size();i++)
    {
        nums[i]=bef[i];
    }

    for(int i=bef.size();i<bef.size()+same;i++)
    {
        nums[i]=pivot;
    }
       for(int i=bef.size()+same, j=0; i<n; i++, j++)
{
    nums[i] = aft[j];
}
        return nums;
    }
};