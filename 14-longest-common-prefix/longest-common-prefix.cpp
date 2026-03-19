class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";

        int n=strs.size();
        sort(strs.begin(),strs.end());
        string ans=strs[0];
        string last=strs[n-1];
        string res="";
        for(int i=0;i<min(ans.size(),last.size());i++)
        {
if(ans[i]!=last[i])
{
    return res;
}
res+=ans[i];

        }
return res;
    }
};