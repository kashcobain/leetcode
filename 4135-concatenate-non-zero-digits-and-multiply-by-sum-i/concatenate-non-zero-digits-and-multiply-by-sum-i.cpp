class Solution {
public:
    long long sumAndMultiply(int n) {

        string ans="";
        int sum=0;

        while(n>0)
        {
            int digit=n%10;

            if(digit!=0)
                ans+=digit+'0';

            sum+=digit;
            n/=10;
        }

        reverse(ans.begin(),ans.end());
        if(ans.size()==0)return 0;

        return stoll(ans)*sum;
    }
};