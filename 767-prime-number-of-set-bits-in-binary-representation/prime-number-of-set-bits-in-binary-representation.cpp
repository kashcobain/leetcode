class Solution {
public:
    bool isprime(int n)
    {
        int cnt=0;
        if(n<=1)
        {
            return false;
        }
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            cnt++;
        }
    }
    if(cnt<=2)return true;
    else{
        return false;
    }
    }
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++)
        {
            int setbits=__builtin_popcount(i);
            if(isprime(setbits))
            {
                count++;
            }

        }
        return count;
    }
};