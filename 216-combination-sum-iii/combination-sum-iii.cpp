class Solution {
public:
    void solve(vector<int> &val, vector<vector<int>> &ans,
               vector<int> &temp, int ind, int k, int n, int sum)
    {
        if(temp.size() == k)
        {
            if(sum == n)
                ans.push_back(temp);
            return;
        }

        if(ind == val.size() || sum > n)
            return;

   
        temp.push_back(val[ind]);
        solve(val, ans, temp, ind + 1, k, n, sum + val[ind]);
        temp.pop_back();

        solve(val, ans, temp, ind + 1, k, n, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> val = {1,2,3,4,5,6,7,8,9};

        vector<vector<int>> ans;
        vector<int> temp;

        solve(val, ans, temp, 0, k, n, 0);

        return ans;
    }
};