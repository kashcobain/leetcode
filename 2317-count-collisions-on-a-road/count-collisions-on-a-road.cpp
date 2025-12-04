class Solution {
public:
    int countCollisions(string s) {
        stack<char> st;
        int n=s.size();
        int count=0;
     
        for(char c:s)
        {
            

            if(c=='R')
            {
                st.push(c);
            }
            else if(c=='S')
            {
                while(!st.empty() && st.top()=='R')
                {
                    count++;
                    st.pop();
                }
                st.push('S');
            }
            else{
                if(st.empty())
                {
                    continue;
                }
                if(st.top()=='S')
                {
                    count++;
                }
                else if(st.top()=='R')
                {
                    count+=2;
                    st.pop();
                    while(!st.empty() && st.top()=='R')
                    {
                        st.pop();
                        count++;
                    }
                }
st.push('S');
            }

        }
        return count;
    }
};