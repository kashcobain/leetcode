class Solution {
public:
    bool ispal(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, string &s, vector<int> &dp) {
        int n = s.size();

        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;

        for(int j = i; j < n; j++) {
            if(ispal(i, j, s)) {
                int cost = 1 + f(j + 1, s, dp);
                mini = min(mini, cost);
            }
        }

        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return f(0, s, dp) - 1;  
    }
};