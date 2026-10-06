class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans = 0;

        stack<char> st;

        for(int i = 0; i < n; i++)
        {
            if(!st.empty() && st.top() == '(' && s[i] == ')')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        ans = max(ans, (int)st.size());

        stack<char> st1;

        for(int i = n - 1; i >= 0; i--)
        {
            if(!st1.empty() && st1.top() == ')' && s[i] == '(')
            {
                st1.pop();
            }
            else
            {
                st1.push(s[i]);
            }
        }

        ans = max(ans, (int)st1.size());

        return ans;
    }
};