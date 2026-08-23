class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<char,int> mp;
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;

        }
        int k=mp[letter];
        return (k*100)/n;
        
    }
};