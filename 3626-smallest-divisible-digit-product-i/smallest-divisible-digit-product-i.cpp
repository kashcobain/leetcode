class Solution {
public:
    int digproduct(int k)
    {
        int pro=1;
        while(k>0)
        {
            int digit=k%10;
            pro=pro*digit;
            k=k/10;
        }
        return pro;
    }
    int smallestNumber(int n, int t) {
        while(n)
        {
            if(digproduct(n)%t==0)
            {
                return n;
            }
            else{
                n++;
            }


        }
        return -1;
    }
};