class Solution {
public:
bool check(string &s)
{
    int n=s.size();
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            return false;
        }
    }
    return true;
} 
string binary(int n)
{
    string ans="";
    while(n>0)
    {
        ans.push_back(n%2+'0');
        n=n/2;
    }
    return ans;
}
    bool hasAlternatingBits(int n) {
        string k=binary(n);
        return check(k);

        
    }
};