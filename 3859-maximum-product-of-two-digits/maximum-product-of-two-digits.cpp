class Solution {
public:
    int maxProduct(int n) {
        string num=to_string(n);
        int k=num.size();

        int ans=0;
        for(int i=0;i<k-1;i++)
        {
            for(int j=i+1;j<k;j++)
            {
                ans=max(ans,(num[i]-'0')*(num[j]-'0'));

            }
        }
        return ans;
    }
};