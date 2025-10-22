class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && s[i] == '#')
                st.pop();
            else if (s[i] != '#')
                st.push(s[i]);
        }

        string ans1 = "";
        while (!st.empty()) {
            ans1 += st.top();
            st.pop();
        }
        reverse(ans1.begin(), ans1.end());

        stack<char> st1;
        for (int i = 0; i < t.size(); i++) {
            if (!st1.empty() && t[i] == '#')
                st1.pop();
            else if (t[i] != '#')
                st1.push(t[i]);
        }

        string ans2 = "";
        while (!st1.empty()) {
            ans2 += st1.top();
            st1.pop();
        }
        reverse(ans2.begin(), ans2.end());

        return ans1 == ans2;
    }
};
