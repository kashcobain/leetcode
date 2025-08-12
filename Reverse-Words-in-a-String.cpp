class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        reverse(s.begin(),s.end());
        int left=0,right=0;
        int i=0;
        while(i<n)
        {
            while(s[i]==' ' && i<n)i++;
            if(i==n)break;
            while(s[i]!=' ' && i<n)
            {
                s[right]=s[i];
                right++;
                i++;
            }
            reverse(s.begin()+left,s.begin()+right);
            s[right++]=' ';
            left=right;
            i++;

        }
        s.resize(right-1);
        return s;
        
    }
};