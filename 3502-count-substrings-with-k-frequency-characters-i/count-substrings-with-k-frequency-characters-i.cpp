class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        int left=0;
        int ans=0;
        vector<int> mp(26,0);
 
        for(int right=0;right<n;right++ )
        {
            mp[s[right]-'a']++;
            while(mp[s[right]-'a']>=k)
            {
                ans+=n-right;
                mp[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};