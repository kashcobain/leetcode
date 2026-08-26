class Solution {
public:
    
    string shortestBeautifulSubstring(string s, int k) {
        
        int n=s.size();
        int j=0;

    string ans="zzzz";
    int size=INT_MAX;
     unordered_map<int,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[s[i]-'0']++;
            while(mp[1]>k)
            {
                mp[s[j]-'0']--;
                j++;
            }
            if(mp[1]==k)
            {
                while(s[j]=='0')
                {
                    mp[s[j]-'0']--;
                    j++;
                }
                string temp=s.substr(j,i-j+1);

                if(temp.size()<size)
                {
                    size=temp.size();
                    ans=temp;
                }
                else if(temp.size()==size)
                {
                    ans=min(ans,temp);
                }

            }
           
           
            


        }
        if(ans=="zzzz")return "";
        return ans;
    }
};