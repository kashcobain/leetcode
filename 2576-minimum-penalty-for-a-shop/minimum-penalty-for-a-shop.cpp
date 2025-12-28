class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> pre(n+1,0);
        vector<int> suff(n+1,0);
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1];
            if(customers[i-1]=='N')pre[i]++;
        }
    for(int i=n-1;i>=0;i--)
    {
        suff[i]=suff[i+1];
        if(customers[i]=='Y')suff[i]++;
    }
int best=INT_MAX;
int pos=0;
for(int i=0;i<=n;i++)
{
    int pen=pre[i]+suff[i];
    if(pen<best)
    {
        best=pen;
        pos=i;
    }
}
return pos;
        
    }
};