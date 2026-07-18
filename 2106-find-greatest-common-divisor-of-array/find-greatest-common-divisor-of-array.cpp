class Solution {
public:
    int findGCD(vector<int>& nums) {
        int ans=1;
        sort(nums.begin(),nums.end());
       
        return gcd(nums[0],nums[nums.size()-1]);
    }
};