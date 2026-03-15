class Solution {
public:

    bool can(long long t, int h, vector<int>& w)
    {
        long long total = 0;

        for(long long wi : w)
        {
            long long k = t / wi;

            long long x = (sqrt(1 + 8.0 * k) - 1) / 2;

            total += x;

            if(total >= h)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long left = 0;
        long long right = 1e18;
        long long ans = 1e18;

        while(left <= right)
        {
            long long mid = left + (right - left) / 2;

            if(can(mid, mountainHeight, workerTimes))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};