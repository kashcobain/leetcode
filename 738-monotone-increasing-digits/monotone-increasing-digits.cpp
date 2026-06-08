class Solution {
public:
    int monotoneIncreasingDigits(int n) {
       string s=to_string(n);
       int k=s.size();
      
       for(int i=s.length()-1;i>0;i--)
       {
        if(s[i]<s[i-1])
        {
            s[i-1]--;
            k=i;
            
        }

       }
       for(int i=k;i<s.size();i++)
       {
        s[i]='9';
       }
return stoi(s);

        
    }
};