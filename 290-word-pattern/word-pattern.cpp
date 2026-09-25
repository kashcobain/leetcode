class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        vector<string> words;
        string word;

      
        for (char c : s) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }

        
        words.push_back(word);


        if (pattern.size() != words.size())
            return false;

        for (int i = 0; i < pattern.size(); i++) {

            char ch = pattern[i];
            string w = words[i];

            if (mp1.find(ch) == mp1.end() &&
                mp2.find(w) == mp2.end()) {

                mp1[ch] = w;
                mp2[w] = ch;
            }
            else {

                if (mp1[ch] != w ||
                    mp2[w] != ch) {

                    return false;
                }
            }
        }

        return true;
    }
};