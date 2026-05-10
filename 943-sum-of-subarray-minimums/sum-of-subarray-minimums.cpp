class Solution {
public:
vector<int> nse(const vector<int> &arr)
{   int n=arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[i]<=arr[st.top()])
        {
            st.pop();
        }
         ans[i]=st.empty()?n:st.top();
        st.push(i);


    }
    return ans;
}
vector<int> pse(const vector<int> &arr)
{
    int n=arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i] )
        {
            st.pop();
        }
      ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        int total=0;
        int mod=(int)(1e9+7);
        vector<int> Nse=nse(arr);
        vector<int> Psee=pse(arr);
        for(int i=0;i<arr.size();i++)
        {
          int  left=i-Psee[i];
          int right=Nse[i]-i;
           total=(total+(left * right * 1LL * arr[i]) % mod) % mod;;

        }
        return total;
    }
};