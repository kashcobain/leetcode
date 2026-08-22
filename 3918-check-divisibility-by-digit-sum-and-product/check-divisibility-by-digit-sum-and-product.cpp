class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int t=n;
        while(n)
        {
            int k=n%10;
            sum+=k;
            product*=k;
            n=n/10;
        }
        return t%(sum+product)==0;
        
    }
};