class Solution {
public:
    bool isval(string s1,string s2)
    {
        if(s1.size()!=s2.size())
        {
            return false;
        }
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
        for(int i=0;i<s1.size();i++)
        {
            if(mp1.find(s1[i])==mp2.end() && mp2.find(s2[i])==mp2.end())
            {
                mp1[s1[i]]=s2[i];
                mp2[s2[i]]=s1[i];

            }
            else{
                if(   mp1[s1[i]]!=s2[i] || mp2[s2[i]]!=s1[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            if(isval(words[i],pattern))
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};