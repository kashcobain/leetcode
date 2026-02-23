class Solution {
public:

    bool hasAllCodes(string s, int k) {
        int count=0;
        int n=s.size();
        if(k>n)return false;
        unordered_set<string> st;
        string ans="";
        for(int i=0;i<k;i++)
        {
            ans+=s[i];
        
        }
        st.insert(ans);
        for(int i=k;i<s.size();i++)
        {
           ans= ans.substr(1);
            ans+=s[i];
            st.insert(ans);
        }
return st.size() == (1 << k);
        
    }
};