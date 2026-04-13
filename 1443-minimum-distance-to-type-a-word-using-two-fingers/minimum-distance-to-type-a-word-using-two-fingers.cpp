class Solution {
public:
    int dist(int a, int b) {
        if(a == 26) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();

        vector<vector<vector<int>>> dp(n+1,
            vector<vector<int>>(27, vector<int>(27, 0)));

    

        for(int i = n-1; i >= 0; i--) {
            int curr = word[i] - 'A';

            for(int f1 = 0; f1 <= 26; f1++) {
                for(int f2 = 0; f2 <= 26; f2++) {

                    int useF1 = dist(f1, curr) + dp[i+1][curr][f2];
                    int useF2 = dist(f2, curr) + dp[i+1][f1][curr];

                    dp[i][f1][f2] = min(useF1, useF2);
                }
            }
        }

        return dp[0][26][26];
    }
};