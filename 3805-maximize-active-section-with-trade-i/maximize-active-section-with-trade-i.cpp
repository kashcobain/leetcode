class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
       int ones=0;
       for(char c:s)
       {
        if(c=='1')
        {
            ones++;
        }
       }

s='1'+s+'1';
int cnt=1;
vector<pair<char,int>> vt;

for(int i=1;i<s.size();i++)
{
    if(s[i]==s[i-1])
    {
        cnt++;
    }
    else{
        vt.push_back({s[i-1],cnt});
        cnt=1;
    }
}
vt.push_back({s.back(),cnt});
int ans=ones;
int maxi=1;
for(int i=1;i<vt.size()-1;i++)
{
    if(vt[i].first=='1' && vt[i-1].first=='0' && vt[i+1].first=='0')
    {
        maxi=max(maxi,ans+vt[i-1].second+vt[i+1].second);
    }
}
if(maxi==1)return ones;

      return maxi;
    }
};