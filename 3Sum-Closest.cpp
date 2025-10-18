class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans;
        int base=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int value=nums[i];
            int low=i+1;
            int high=n-1;
while(low<high)
{int sum=nums[i]+nums[low]+nums[high];
   if(abs(sum-target)<abs(base-target))
   {
    base=sum;
   }
    if(sum<target)
    {
        low++;
    }
    else if(sum>target){
        high--;
    }
    else{
        return target;
    }
   

}      

  }
  return base;
        
    }
};