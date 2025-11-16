class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        long long count = 0;
        const int mod = 1e9 + 7;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                count++;
                ans = (ans + count) % mod;
            } else {
                count = 0;
            }
        }
        
        return (int) ans; 
    }
};
