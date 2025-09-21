class Solution {
public:
    long long mod = 1e9+7;

    // fast power: a^b % mod
    long long power(long long a, long long b) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // number of even indices
        long long odd  = n / 2;       // number of odd indices
        return (power(5, even) * power(4, odd)) % mod;
    }
};
