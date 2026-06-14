class Solution {
public:
    bool iseq(int n)
    {
        int cnt=0;
        int z=n;
        int val=0;
        while(z!=0)
        {
            z=z/2;
            val++;
        }
        while(n!=0)
        {
            n=n&(n-1);
            cnt++;
        }
        return cnt==val;

    }
    int countMonobit(int n) {
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            if(iseq(i))
            {
                ans++;
            }
        }
        return ans;

    }
};