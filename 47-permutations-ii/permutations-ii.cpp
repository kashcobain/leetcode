class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp,vector<bool> &used)
    {
        int n=nums.size();
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(used[i])continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1])continue;
            used[i]=true;
        temp.push_back(nums[i]);
        backtrack(nums,ans,temp,used);

        used[i]=false;
                        temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(n,false);
        backtrack(nums,ans,temp,used);
        return ans;
        
    }
};