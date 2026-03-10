class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        string ss=s+s;
        int ans=INT_MAX;
        int diff0=0,diff1=0;
        for(int i=0;i<ss.size();i++)
        {
            char exp1=(i%2==0)?'0':'1';
            char exp2=(i%2==0)?'1':'0';
            if(ss[i]!=exp1)diff0++;
            if(ss[i]!=exp2)diff1++;
            if(i>=n)
            {
                char p1=((i-n)%2==0)?'0':'1';
                char p2=((i-n)%2==0)?'1':'0';
                if(ss[i-n]!=p1)diff0--;
                if(ss[i-n]!=p2)diff1--;


            }




            if(i>=n-1)
            {
                ans=min(ans,min(diff0,diff1));
            }

        }

return ans;
        
    }
};