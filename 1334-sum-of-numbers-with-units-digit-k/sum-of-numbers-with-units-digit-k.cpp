class Solution {
public:

    int minimumNumbers(int num, int k) {

        if(num == 0)
            return 0;

        vector<int> coins;
        for(int i = k; i <= num; i += 10)
        {
            coins.push_back(i);
        }
        vector<int> dp(num + 1, 1e9);
        dp[0] = 0;
        for(int coin : coins)
        {
            for(int target = coin;
                target <= num;
                target++)
            {
                dp[target] =
                    min(dp[target],
                        1 + dp[target - coin]);
            }
        }

        return dp[num] == 1e9
               ? -1
               : dp[num];
    }
};