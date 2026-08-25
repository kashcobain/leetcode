class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        int n = nums.size();

        vector<long long> pre(n + 1, 0);
        vector<long long> suf(n + 1, 0);

       
        for(int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + nums[i];
        }

       
        for(int i = n - 1; i >= 0; i--)
        {
            suf[i] = suf[i + 1] + nums[i];
        }

        long long mini = LLONG_MAX;
        int ansIndex = 0;

        for(int i = 0; i < n; i++)
        {
           
            long long left = pre[i + 1] / (i + 1);

           
            long long right = 0;

            if(i != n - 1)
            {
                right = suf[i + 1] / (n - i - 1);
            }

            long long diff = abs(left - right);

            if(diff < mini)
            {
                mini = diff;
                ansIndex = i;
            }
        }

        return ansIndex;
    }
};