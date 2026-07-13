class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)return {};
        vector<int> k=arr;
        sort(k.begin(),k.end());
        unordered_map<int,int> mp;
        mp[k[0]]=1;
        int rank=1;
        for(int i=1;i<k.size();i++)
        {
            if(k[i]==k[i-1])
            {
                mp[k[i]]=mp[k[i-1]];


                
            }
            else{
                rank++;
                mp[k[i]]=rank;
                
            }
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
        {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};