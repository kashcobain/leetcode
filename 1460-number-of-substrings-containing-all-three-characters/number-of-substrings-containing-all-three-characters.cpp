class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int cnt=0;
        int i=0;
        int j=0;
        while(j<n)
        {
            mp[s[j]]++;
            while(mp.find('a')!=mp.end() && mp.find('b')!=mp.end() && mp.find('c')!=mp.end()
            )
            {
                cnt+=n-j;
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            j++;
            
        }
return cnt;
        
    }
};