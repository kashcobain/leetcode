class Solution {
public:

    int hammingWeight(int n) {
        string ans="";
        while(n>0)
        {
            ans.push_back(n%2+'0');
          n=  n/2;
        }
        int count=0;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='1')
            {
                count++;
            }

        }
        return count;
    }
};