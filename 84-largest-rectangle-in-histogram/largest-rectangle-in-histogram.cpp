class Solution {
public:

    vector<int> pse(vector<int>& heights, int n)
    {
        stack<int> st;

        vector<int> ans(n);

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() &&
                  heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> nse(vector<int>& heights, int n)
    {
        stack<int> st;

        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() &&
                  heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> prev = pse(heights, n);

        vector<int> next = nse(heights, n);

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int width =
                next[i] - prev[i] - 1;

            int area =
                width * heights[i];

            ans = max(ans, area);
        }

        return ans;
    }
};