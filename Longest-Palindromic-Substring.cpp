class Solution {
public:
    bool ispal(string &s, int i, int j, vector<vector<int>> &dp) {
        if (dp[i][j] != -1) return dp[i][j] == 1;
        if (i >= j) {
            dp[i][j] = 1;
            return true;
        }
        if (s[i] != s[j]) {
            dp[i][j] = 0;
            return false;
        }

        if (ispal(s, i + 1, j - 1, dp)) {
            dp[i][j] = 1;
            return true;
        } else {
            dp[i][j] = 0;
            return false;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        if (n == 1) return s;

        int maxlen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (ispal(s, i, j, dp)) {
                    int len = j - i + 1;
                    if (len > maxlen) {
                        maxlen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxlen);
    }
};
