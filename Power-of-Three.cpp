class Solution {
public:
    bool isPowerOfThree(int n) {
        unordered_map<int,int> mp;
        if(n<=0)
        {
            return false;
        }
        if(n==1)
        {
            return true;
        }

        while(n%3==0)
        {
            n=n/3;
        }
       return n==1;
        
    }
};