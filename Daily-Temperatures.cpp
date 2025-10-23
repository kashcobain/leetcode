class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
stack<int> st;
vector<int> ans(n,0);
for(int i=0;i<n;i++)
{
    int currtemp=temp[i];
    while(!st.empty() && temp[st.top()]<currtemp)
    {
        int prev=st.top();
        st.pop();
        ans[prev]=i-prev;
    }
    st.push(i);
}
        return ans;
    }
};