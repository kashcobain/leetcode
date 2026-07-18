class Solution {
public:
    int smallestEvenMultiple(int n) {
        bool odd=(n%2==0)?false:true;
        if(odd)
        {
            return 2*n;
        }
        else{
            return n;
        }

        
    }
};