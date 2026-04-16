class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

 
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(int q : queries) {

            auto &vec = mp[nums[q]];

         
            if(vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            auto it = lower_bound(vec.begin(), vec.end(), q);

            int mini = INT_MAX;

            int idx;
            if(it + 1 != vec.end())
                idx = *(it + 1);
            else
                idx = vec[0];

            int d = min((idx - q + n) % n, (q - idx + n) % n);
            mini = min(mini, d);

       
            if(it != vec.begin())
                idx = *(it - 1);
            else
                idx = vec.back();

            d = min((idx - q + n) % n, (q - idx + n) % n);
            mini = min(mini, d);

            ans.push_back(mini);
        }

        return ans;
    }
};