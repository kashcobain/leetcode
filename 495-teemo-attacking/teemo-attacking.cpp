class Solution {
public:
    vector<vector<int>> merger(vector<vector<int>> &arr)
    {
        int n=arr.size();
        vector<vector<int>> res;
        vector<int> prev=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i][0]<=prev[1])
            {
                prev[1]=max(prev[1],arr[i][1]);

            }
            else{
                res.push_back(prev);
                prev=arr[i];
            }
        }
        res.push_back(prev);
        return res;
    }
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n=timeSeries.size();
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({timeSeries[i],timeSeries[i]+duration-1});
            
        }
        int val=0;
        vector<vector<int>> ans=merger(arr);
        for(int i=0;i<ans.size();i++)
        {
            val+=ans[i][1]-ans[i][0]+1;

        }
        return val;
        
    }
};