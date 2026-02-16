class Solution {
public:
    string tobin(unsigned int n)
    {
        string ans = "";
        
        for(int i = 0; i < 32; i++)
        {
            int bit = n % 2;
            ans.push_back(bit + '0');
            n = n / 2;
        }
        
        return ans;
    }

    unsigned int toDecimal(string k)
    {
        unsigned int val = 0;
        int n = k.size();
        
        for(int i = 0; i < n; i++)
        {
            if(k[i] == '1')
            {
                val += (1u << (n - i - 1));
            }
        }
        
        return val;
    }

    int reverseBits(int n) {
        string k = tobin(n);
        return toDecimal(k);
    }
};
