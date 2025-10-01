class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        // Step 1: base row dal do
        vector<vector<int>> dp; 
        dp.push_back(nums);   // dp[0] = original nums

        // Step 2: har step pe ek row chhoti hoti jaayegi
        for (int i = 1; i < n; i++) {
            int size = n - i;
            vector<int> row(size);

            for (int j = 0; j < size; j++) {
                row[j] = (dp[i-1][j] + dp[i-1][j+1]) % 10;
            }

            dp.push_back(row);
        }

        // Step 3: last row me ek hi element hoga
        return dp[n-1][0];
    }
};
