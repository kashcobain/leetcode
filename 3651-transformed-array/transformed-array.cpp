class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
vector<int> arr(n,0);
for(int i=0;i<n;i++)
{
    arr[i]=nums[((i+nums[i])%n+n)%n];
}
return arr;
              
    }
};