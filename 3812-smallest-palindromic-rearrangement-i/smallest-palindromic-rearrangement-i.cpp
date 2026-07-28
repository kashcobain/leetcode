class Solution {
public:
    string smallestPalindrome(string p) {
        vector<int> lett(26, 0);

        for (auto it : p) {
            lett[it - 'a']++;
        }

        string s = "";
        char middle = '\0';

        bool flag = false;

        for (int i = 0; i < 26; i++) {  

            
            for (int j = 0; j < lett[i] / 2; j++) {
                s += char('a' + i);
            }

            
            if (lett[i] % 2 != 0 && flag == false) {
                middle = char('a' + i);
                flag = true;
            }
        }

        string ans = s;
        reverse(s.begin(), s.end());

        if (middle != '\0')
            return ans + middle + s;

        return ans + s;
    }
};