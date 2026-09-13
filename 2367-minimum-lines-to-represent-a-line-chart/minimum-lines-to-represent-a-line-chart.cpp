class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        vector<vector<int>> sp = stockPrices;
        int n = sp.size();

        sort(sp.begin(), sp.end());

        if(n <= 1)
            return 0;

        int ans = 1;

        long long prevNum = sp[1][1] - sp[0][1];
        long long prevDeno = sp[1][0] - sp[0][0];

        for(int i = 2; i < n; i++)
        {
            long long num = sp[i][1] - sp[i-1][1];
            long long deno = sp[i][0] - sp[i-1][0];

            if(num * prevDeno != prevNum * deno)
            {
                ans++;
            }

            prevNum = num;
            prevDeno = deno;
        }

        return ans;
    }
};