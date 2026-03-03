class Solution {
public:
    string invert(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
        return s;
    }

    char findKthBit(int n, int k) {
        string si = "0";

        for(int i = 1; i < n; i++) {
            string rev = si;
            reverse(rev.begin(), rev.end());
            rev = invert(rev);

            si = si + "1" + rev;
        }

        return si[k-1];
    }
};