class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
               c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }

    string sortVowels(string s) {
        vector<int> index;
        vector<char> var;

        // Step 1: Collect vowels and their indices
        for(int i=0; i<s.size(); i++) {
            if(isVowel(s[i])) {
                index.push_back(i);
                var.push_back(s[i]);
            }
        }

        // Step 2: Sort vowels
        sort(var.begin(), var.end());

        // Step 3: Put them back into string
        for(int i=0; i<index.size(); i++) {
            s[index[i]] = var[i];
        }

        return s;
    }
};
