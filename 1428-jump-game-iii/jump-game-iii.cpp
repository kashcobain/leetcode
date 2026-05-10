class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int> q;
        vector<int> vis(n,0);
        q.push(start);
        vis[start]=1;
        while(!q.empty())
        {
            int ind=q.front();
            q.pop();
            if(arr[ind]==0)
            {
                return true;
            }
            int fwd=ind+arr[ind];
            int bwd=ind-arr[ind];
            if(fwd <n && vis[fwd]==0)
            {
                q.push(fwd);
                vis[fwd]=1;
            }
            if(bwd>=0 && vis[bwd]==0)
            {
                q.push(bwd);
                vis[bwd]=1;
            }

        }
        return false;
    }
};