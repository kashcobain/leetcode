class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string s;
        unordered_map<char,int> mp;
        for(int i=0;i<brokenLetters.size();i++)
        {
            mp[brokenLetters[i]]++;
        }
      vector<string> v;
        while(getline(ss,s,' ')){
            v.push_back(s);
            

        }
        int count=0;
        for(int i=0;i<v.size();i++)
        {
          string p=v[i];
          int k=p.size();
          for(int j=0;j<k;j++)
          {
            if(mp[p[j]]!=0)
            {
                count++;
                break;
            }
          }

        }
        return v.size()-count;
    }
};