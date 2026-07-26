class Solution {
public:
    long long maxProduct(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
    
                return max({1LL*nums[0]*nums[n-1]*-100000,1LL*nums[0]*nums[1]*100000,1LL*nums[n-1]*nums[n-2]*100000});
       

        
    }
};