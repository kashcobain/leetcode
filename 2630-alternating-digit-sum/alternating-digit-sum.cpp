class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> ans;
        while(n>0)
        {
            int k=n%10;
            ans.push_back(k);
            n=n/10;
        }
        reverse(ans.begin(),ans.end());
        int val=0;
        int sign=1;
        for(int i=0;i<ans.size();i++)
        {
            val+=ans[i]*sign;
            sign=-sign;
        }
        
        return val;
        
    }
};