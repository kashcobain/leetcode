class Solution {
public:
    int countEven(int num) {
        int count=0;
        int sum=0;
        for(int i=2;i<=num;i++)
        {
           int j=i;
            while(j>0)
            {
                int last=j%10;
                sum+=last;
                j=j/10;
            }
            if(sum%2==0)
            {
                count++;
            }
            sum=0;
        }
        return count;
    }
};