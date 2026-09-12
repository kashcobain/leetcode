class Solution {
public:

    struct cmp{
        bool operator()(vector<int> &l, vector<int> &r)
        {
            if(l[0] != r[0])
                return l[0] < r[0];

            return l[1] < r[1];
        }
    };

    int solve(int i, vector<vector<int>> &arr, vector<int> &dp)
    {
        if(i >= arr.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int notpick = solve(i + 1, arr, dp);

        int start = arr[i][0];
        int pro = arr[i][2];

        int next = arr.size();

        int low = i + 1;
        int high = arr.size() - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(arr[mid][0] >= arr[i][1])
            {
                next = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        int pick = pro + solve(next, arr, dp);

        return dp[i] = max(pick, notpick);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        int n = startTime.size();

        vector<vector<int>> arr;

        for(int i = 0; i < n; i++)
        {
            arr.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(arr.begin(), arr.end(), cmp());

        vector<int> dp(n, -1);

        return solve(0, arr, dp);
    }
};