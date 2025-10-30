class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";

        unordered_map<char,int> mps, mpt;
        for (char c : t) {
            mpt[c]++;
        }

        int required = mpt.size();
        int count = 0;
        int i = 0, start = 0;
        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            char c = s[j];
            mps[c]++;

            if (mpt.find(c) != mpt.end() && mps[c] == mpt[c]) {
                count++;
            }

          
            while (count == required) {
                if (j - i + 1 < ans) {
                    ans = j - i + 1;
                    start = i;
                }

                char leftChar = s[i];
                mps[leftChar]--;

                if (mpt.count(leftChar) && mps[leftChar] < mpt[leftChar]) {
                    count--;
                }

                i++;
            }
        }

        return (ans == INT_MAX) ? "" : s.substr(start, ans);
    }
};
