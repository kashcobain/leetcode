class Solution {
public:
    long long countCommas(long long n) {

        long long ans = 0;

        if(n >= 1000)
        {
            long long cnt = min(n, 999999LL) - 1000 + 1;
            ans += cnt;
        }

        if(n >= 1000000)
        {
            long long cnt = min(n, 999999999LL) - 1000000 + 1;
            ans += cnt * 2;
        }

        if(n >= 1000000000)
        {
            long long cnt = min(n, 999999999999LL) - 1000000000LL + 1;
            ans += cnt * 3;
        }

       if(n >= 1000000000000LL)
{
    long long cnt = min(n, 999999999999999LL)
                    - 1000000000000LL + 1;
    ans += cnt * 4;
}

if(n >= 1000000000000000LL)
{
    long long cnt = n - 1000000000000000LL + 1;
    ans += cnt * 5;
}
        return ans;
    }
};