class Solution {
public:
    struct cmp{
        bool operator()(string &s1,string &s2) const
        {
            return s1.size() < s2.size();
        }
    };

    bool compare(string &s1,string &s2)
    {
        if(s1.size() != s2.size()+1) return false;

        int i=0, j=0;

        while(i<s1.size())
        {
            if( s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return (j==s2.size()&&i==s1.size());
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> dp(n,1);
        int len=1;

        sort(words.begin(),words.end(),cmp());

        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(compare(words[i],words[prev]) && dp[prev]+1>dp[i])
                {
                    dp[i]=dp[prev]+1;
                }
            }
            len=max(len,dp[i]);
        }

        return len;
    }
};