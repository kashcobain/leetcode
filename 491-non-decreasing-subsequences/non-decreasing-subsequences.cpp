class Solution {
public:
    void solve(int idx, int n,
               set<vector<int>>& st,
               vector<int>& temp,
               vector<int>& nums,
               int prev)
    {
        if(idx >= n)
        {
            if(temp.size() >= 2)
            {
                st.insert(temp);
            }
            return;
        }

        if(nums[idx] >= prev)
        {
            temp.push_back(nums[idx]);

            solve(idx + 1, n, st, temp, nums, nums[idx]);

            temp.pop_back();
        }

        solve(idx + 1, n, st, temp, nums, prev);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {

        int n = nums.size();

        vector<int> temp;
        set<vector<int>> st;

        solve(0, n, st, temp, nums, INT_MIN);

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};