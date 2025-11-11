class Solution {
public:
    int minSteps(int n) {
        if(n==1)return 0;
        return 1+minhelper(1,1,n);
        
    }
    int minhelper(int curlen,int pastlen,int n)
    {
        if(curlen==n)return 0;
        if(curlen>n)return 1000;
        int op1=2+minhelper(curlen*2,curlen,n);
        int op2=1+minhelper(curlen+pastlen,pastlen,n);
        return min(op1,op2);
    }
};