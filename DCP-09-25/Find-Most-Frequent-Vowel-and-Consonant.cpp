class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vow;
        unordered_map<char,int> cons;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'  )
            {
                vow[s[i]]++;
            }
            else{
                cons[s[i]]++;
            }
        }
        int vomax=0;
        int consmax=0;
        for(auto it:vow)
        {
            vomax=max(vomax,it.second);
        }
        for(auto it:cons)
        {
            consmax=max(consmax,it.second);
        }
        return consmax+vomax;
    }
};