class Solution {
public:
    bool solve(int ind,vector<int>& arr,vector<bool> &vis)
    {
        int n=arr.size();
        if(arr[ind]==0)return true;
        bool c1=false;
        bool c2=false;
        if(vis[ind])return false;
        vis[ind]=true;
        if(ind+arr[ind]<n) c1=solve(ind+arr[ind],arr,vis);
        if(ind-arr[ind]>=0) c2=solve(ind-arr[ind],arr,vis);
        return c1||c2;

    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> vis(n, false);
        return solve(start,arr,vis);
        
    }
};