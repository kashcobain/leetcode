class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        map<pair<char,char>, int> mp;
        int length = 0;

        for(int i = 0; i < n; i++) {
            char f = words[i][0];
            char s = words[i][1];

            // reverse pair check karo
            if(mp[{s,f}] > 0) {
                length += 4;
                mp[{s,f}]--;
            } else {
                mp[{f,s}]++;
            }
        }

        
        for(auto &it : mp) {
            if(it.first.first == it.first.second && it.second > 0) {
                length += 2;
                break;
            }
        }

        return length;
    }
};
