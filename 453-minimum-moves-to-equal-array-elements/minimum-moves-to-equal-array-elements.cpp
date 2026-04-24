class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int ans=0;


        sort(nums.begin(),nums.end());
        int total=accumulate(nums.begin(),nums.end(),0);
        return total-nums[0]*n;

        

        
    }
};