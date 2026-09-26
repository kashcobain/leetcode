class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        int i = 0;

        while (i < s.size()) {

            if (s[i] == '(') {
                int start = i;
                int end = i + 1;

                while (s[end] != ')') {
                    end++;
                }

                string word = s.substr(start + 1, end - start - 1);

                string replacement = "?";

                if (mp.find(word) != mp.end()) {
                    replacement = mp[word];
                }

                s.replace(start, end - start + 1, replacement);

                i = start + replacement.size();
            }
            else {
                i++;
            }
        }

        return s;
    }
};
