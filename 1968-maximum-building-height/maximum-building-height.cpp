class Solution {
public:
    int maxBuilding(int p, vector<vector<int>>& restrictions) {
        vector<vector<int>> arr;
        arr.push_back({1,0});
        for(auto k:restrictions)
        {
            arr.push_back(k);
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            int d=arr[i][0]-arr[i-1][0];
            arr[i][1]=min(arr[i][1],arr[i-1][1]+d);
        }
        for(int i=n-2;i>=0;i--)
        {
            int d=arr[i+1][0]-arr[i][0];
            arr[i][1]=min(arr[i][1],arr[i+1][1]+d);
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int x1=arr[i-1][0];
            int h1=arr[i-1][1];
            int x2=arr[i][0];
            int h2=arr[i][1];
            int d=x2-x1;
            ans=max(ans,(h1+h2+d)/2);

        }
        int lastpos=arr.back()[0];
        int lasth=arr.back()[1];
        ans=max(ans,(lasth+p-lastpos));
        return ans;
    }

};