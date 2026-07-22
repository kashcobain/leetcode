class Solution {
public:
    void solve(vector<int>& cand, vector<vector<int>>& ans,
               vector<int>& temp, int ind, int sum, int n, int target)
    {
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }

        if(ind == n || sum > target)
            return;


        temp.push_back(cand[ind]);
        solve(cand, ans, temp, ind + 1, sum + cand[ind], n, target);
        temp.pop_back();

   
        while(ind + 1 < n && cand[ind] == cand[ind + 1])
            ind++;

 
        solve(cand, ans, temp, ind + 1, sum, n, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, ans, temp, 0, 0, candidates.size(), target);

        return ans;
    }
};