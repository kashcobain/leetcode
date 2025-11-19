class Solution {
public:
    void backtrack( vector<vector<int>> &ans,vector<int> temp,vector<int>& nums,int start)
    {
        int n=nums.size();
        ans.push_back(temp);
        for(int i=start;i<n;i++)
        {
            temp.push_back(nums[i]);
            backtrack(ans,temp,nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        backtrack(ans,temp,nums,0);
        return ans;

        
    }
};