class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        stack<char> st;
     for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
               
                if (!st.empty()) st.pop();
            } else {
             
                st.push(s[i]);
            }
        }
        string ans="";
        int k=st.size();
        for(int i=0;i<k;i++)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};