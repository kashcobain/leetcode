class Solution {
public:
    string largestGoodInteger(string num) {
        int r=2;
                    int k=-1;

        for(int l=0;l<num.size()-2;l++)
        {
            if(num[l]==num[r] && num[l+1]==num[r])
            {
                char j=num[l];
                int p=num[l]-'0';
                k=max(p,k);


            }
            r++;
        }
        if(k==-1)
        {
            return "";
        }
       string s(3,char(k+'0'));
       return s;
    }
};