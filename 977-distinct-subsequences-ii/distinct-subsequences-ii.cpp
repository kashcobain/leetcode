class Solution {
public:

    int MOD = 1e9 + 7;

    long long solve(int i, string &s, vector<int> &prev, vector<long long> &dp)
    {
        if(i == 0)
            return 1;

        if(dp[i] != -1)
            return dp[i];

        long long ans = 2 * solve(i - 1, s, prev, dp);

        if(prev[i - 1] != -1)
            ans -= solve(prev[i - 1], s, prev, dp);

        ans %= MOD;

        return dp[i] = ans;
    }

    int distinctSubseqII(string s)
    {
        int n = s.size();

        vector<int> prev(n, -1);
        vector<int> last(26, -1);

        for(int i = 0; i < n; i++)
        {
            int ch = s[i] - 'a';

            prev[i] = last[ch];

            last[ch] = i;
        }

        vector<long long> dp(n + 1, -1);

        return (solve(n, s, prev, dp) - 1 + MOD) % MOD;
    }
};