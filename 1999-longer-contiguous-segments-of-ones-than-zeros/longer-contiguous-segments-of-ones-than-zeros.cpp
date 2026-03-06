class Solution {
public:
    bool checkZeroOnes(string s) {

        int ones = 0, zeros = 0;
        int max1 = 0, max0 = 0;

        for(char c : s)
        {
            if(c == '1')
            {
                ones++;
                zeros = 0;
            }
            else
            {
                zeros++;
                ones = 0;
            }

            max1 = max(max1, ones);
            max0 = max(max0, zeros);
        }

        return max1 > max0;
    }
};