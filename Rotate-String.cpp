class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        string k=s+s;
        for(int i=0;i<n;i++)
        {
            s+=s[i];
            string v=s.substr(i+1,n+1);
            if(v==goal)
            {
                return true;
            }
        }
        return false;

        
    }
};