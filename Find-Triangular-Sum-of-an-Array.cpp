class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev=nums;
        for(int i=n;i>1;i--)
        {
            vector<int> curr(i-1);
            for(int j=0;j<i-1;j++)
            {
                curr[j]=(prev[j]+prev[j+1])%10;
            }
            prev=curr;
        }
return prev[0];
    }
};