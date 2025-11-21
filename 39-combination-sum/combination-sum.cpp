class Solution {
public:
    void combi(vector<int>& candidates, int target,
               vector<int> &temp, vector<vector<int>> &ans,
               int start, int sum) 
    {
        // sum target ke equal -> ek valid combination mil gaya
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        // sum exceed ho gaya -> is path se aage kuch nahi milega
        if (sum > target) return;

        int n = candidates.size();
        for (int i = start; i < n; ++i) {
            // choose candidates[i]
            temp.push_back(candidates[i]);
            combi(candidates, target, temp, ans, i, sum + candidates[i]); 
            //        ^^^^^^ reuse allowed, isliye i pass (not i+1)
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        combi(candidates, target, temp, ans, 0, 0);
        return ans;
    }
};
