class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
{
    int l=0;
    unordered_map<char,int> mp;

    for(int j=i;j<n;j++)
    {
       

        mp[s[j]]++;

        if(mp[s[j]]>=k)
        {
            count+=n-j;
            break;
        }
    }
}
        return count;
    }
};