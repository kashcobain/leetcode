class Solution {
public:
    void backtrack(vector<vector<int>> &ans,vector<int> &temp,vector<int> &nums,int start)
    {
        int n=nums.size();
       ans.push_back(temp);

        
        for(int i=start;i<n;i++)
        {
            if(i>start &&nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            backtrack(ans,temp,nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        backtrack(ans,temp,nums,0);
        return ans;
    }
};