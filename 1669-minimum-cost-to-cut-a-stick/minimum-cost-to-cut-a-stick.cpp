class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int k = cuts.size();
        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        vector<vector<int>> dp(k+2, vector<int>(k+2, 0));

        for(int i = k; i >= 1; i--) {
            for(int j = i; j <= k; j++) {
                int mini = INT_MAX;

                for(int ind = i; ind <= j; ind++) {
                    int cost = cuts[j+1] - cuts[i-1]
                             + dp[i][ind-1]
                             + dp[ind+1][j];

                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][k];
    }
};