class Solution {
public:
    bool isCircularSentence(string s) {
        int n=s.size();
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
          if(s[i]==' ')
          {
            if(s[i-1]!=s[i+1])
            {
                return false;
            }
          }
            
        }
        if(s[n-1]==s[0])
        {
            return true;
        }
        else{
            return false;
        }
    }
};