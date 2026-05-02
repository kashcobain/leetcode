class Solution {
public:
    int solve(string s,int pos,bool tight,bool changed)
    {
        if(pos==s.size())
        {
            return changed?1:0;
            
        }
        int ans=0;
        int limit=(tight?(s[pos]-'0'):9);
        for(int d=0;d<=limit;d++)
        {
            if(d==3||d==4||d==7)continue;
            bool newtight=(tight && (d==limit));
            bool newChanged = changed;
            if (d == 2 || d == 5 || d == 6 || d == 9)
            newChanged=true;
            ans += solve(s, pos + 1, newtight, newChanged);

        }
        return ans;
    }
    int rotatedDigits(int n) {
        string s=to_string(n);
        return solve(s,0,true,false);
        
    }
};