class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> words;
        for(auto it:s)
        {
            words.insert(it);
        }
        int ans=0;
        for(char word:words)
        {
            int i=-1;
            int j=-0;
            for(int l=0;l<s.size();l++)
            {
                if(s[l]==word)
                {
                    if(i==-1)
                    {
                        i=l;
                    }
                    j=l;

                }
            }
            unordered_set<char> sizeset;
           for(int l=i+1;l<j;l++)
           {
            sizeset.insert(s[l]);
           }
           int size=sizeset.size();
           ans+=size;
        }
        return ans;
    }
};