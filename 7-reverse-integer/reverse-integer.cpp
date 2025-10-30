class Solution {
public:
    int reverse(int x) {
        long long num = x;          
        bool neg = (num < 0);
        if (neg) num = -num;        

        string s = to_string(num);
        std::reverse(s.begin(), s.end());

        long long val = stoll(s);
        if (neg) val = -val;

        if (val > INT_MAX || val < INT_MIN) return 0;

        return (int)val;
    }
};
