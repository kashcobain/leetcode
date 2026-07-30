class Solution {
public:
    int minimumPushes(string word) {
       int n=word.size();
       int ans=0;
       if(n<=8)
       {
        ans+=n;
       }
       else if(n>8 && n<=16)
       {
        ans+=8;
        ans+=2*(n-8);
       }
       else if(n>16 && n<=24)
       {
        ans+=24;
        ans+=3*(n-16);
       }
       else{
        ans+=48;
        ans+=4*(n-24);
       }

return ans;
    }

};