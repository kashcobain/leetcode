class Solution {
public:
    string maskVowels(string s) {
        for (char &c : s) {
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c = '*';
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap, vowelMap;

        for (string w : wordlist) {
            string lower = w;
            for (char &c : lower) c = tolower(c);

            if (!caseMap.count(lower)) caseMap[lower] = w;

            string masked = maskVowels(lower);
            if (!vowelMap.count(masked)) vowelMap[masked] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {  // exact match
                ans.push_back(q);
                continue;
            }
            string lower = q;
            for (char &c : lower) c = tolower(c);

            if (caseMap.count(lower)) {  // case-insensitive match
                ans.push_back(caseMap[lower]);
                continue;
            }
            string masked = maskVowels(lower);
            if (vowelMap.count(masked)) {  // vowel error match
                ans.push_back(vowelMap[masked]);
                continue;
            }
            ans.push_back("");  // no match
        }
        return ans;
    }
};
