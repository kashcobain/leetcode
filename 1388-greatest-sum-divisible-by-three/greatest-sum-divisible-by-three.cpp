class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        int sum = 0;

        int m1a = INT_MAX, m1b = INT_MAX;
        int m2a = INT_MAX, m2b = INT_MAX; 

        for (int i = 0; i < n; i++)
        {
            int v = nums[i];
            sum += v;
            int k = v % 3;

            if (k == 1)
            {
             
                if (v < m1a) {
                    m1b = m1a;
                    m1a = v;
                } else if (v < m1b) {
                    m1b = v;
                }
            }
            else if (k == 2)
            {
                if (v < m2a) {
                    m2b = m2a;
                    m2a = v;
                } else if (v < m2b) {
                    m2b = v;
                }
            }
        }

        if (sum % 3 == 0) return sum;

        int ans = 0;

        if (sum % 3 == 1) {
            int op1 = (m1a == INT_MAX ? 0 : sum - m1a);                   
            int op2 = (m2a == INT_MAX || m2b == INT_MAX ? 0 : sum - m2a - m2b); 
            ans = max(op1, op2);
        } else if (sum % 3 == 2) {
            int op1 = (m2a == INT_MAX ? 0 : sum - m2a);                   
            int op2 = (m1a == INT_MAX || m1b == INT_MAX ? 0 : sum - m1a - m1b); 
            ans = max(op1, op2);
        }

        return ans; 
    }
};
