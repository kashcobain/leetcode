class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        if(n==0)return {};
        vector<int> ans(n,-1);
       int maxi=arr[n-1];
        for(int i=n-2;i>=0;i--)
    {ans[i]=maxi;
        if(arr[i]>=maxi)
        {
            maxi=arr[i];
        }
        

    }
      
        return ans;
    }
};