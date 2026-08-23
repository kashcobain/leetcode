class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int leftcnt=0;
        int sum1=0;
        int rightcnt=0;
        int sum2=0;
        for(int i=0;i<n/2;i++)
        {
            if(num[i]=='?')
            {
                leftcnt++;
            }
            else{
                sum1+=num[i]-'0';
            }
        }
        for(int i=n/2;i<n;i++)
        {
            if(num[i]=='?')
            {
                rightcnt++;
            }
            else{
                sum2+=num[i]-'0';
            }
        }
        int dif=(sum1-sum2);
        if(leftcnt==0 && rightcnt==0)
        {
            return dif!=0;
        }
        if((leftcnt-rightcnt)%2!=0)return true;

       
        if(dif==9*(rightcnt - leftcnt) / 2)
        {
            return false;
        }
        return true;
    }
};