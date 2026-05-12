class Solution {
public:
    vector<int> pse(vector<int> &arr)
    {
        int n=arr.size();
    
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(i);
        }

        return ans;
    }
    vector<int> nse(vector<int> &arr)
    {
        int n=arr.size();
    
        stack<int> st;
        vector<int> ans(n,n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(i);
        }

        return ans;
    }
    int hist(vector<int> &arr)
    {
        vector<int> pre=pse(arr);
        vector<int> next=nse(arr);
        int maxi=0;
        for(int i=0;i<arr.size();i++)
        {
            maxi=max(maxi,(next[i]-pre[i]-1)*arr[i]);
        }
return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            maxi=max(maxi,hist(heights));
        }
        return maxi;
    }
};