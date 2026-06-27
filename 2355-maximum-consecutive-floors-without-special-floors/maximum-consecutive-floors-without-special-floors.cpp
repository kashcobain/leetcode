class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        vector<int> arr(special.begin(),special.end());
        arr.push_back(bottom);
        arr.push_back(top);
        sort(arr.begin(),arr.end());
        int ans=max(arr[1]-arr[0],arr[arr.size()-1]-arr[arr.size()-2]);
        for(int i=2;i<arr.size()-1;i++)
        {
            int k=(arr[i]-arr[i-1]-1);
            ans=max(k,ans);


        }
        return ans;
        


        
    }
};