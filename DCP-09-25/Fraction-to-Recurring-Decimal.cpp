class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string res = "";
        
        // sign handle
        if ((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }
        
        // convert to positive long long
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        
        // integer part
        res += to_string(n / d);
        long long rem = n % d;
        
        if (rem == 0) return res;
        
        res.push_back('.');
        unordered_map<long long, int> seen;
        
        while (rem != 0) {
            if (seen.find(rem) != seen.end()) {
                int pos = seen[rem];
                res.insert(pos, "(");
                res.push_back(')');
                break;
            }
            seen[rem] = res.size();
            
            // ⚡ use __int128 to avoid overflow
            __int128 bigRem = rem;
            bigRem *= 10;
            
            int digit = bigRem / d;
            res.push_back('0' + digit);
            
            rem = bigRem % d;
        }
        return res;
    }
};
