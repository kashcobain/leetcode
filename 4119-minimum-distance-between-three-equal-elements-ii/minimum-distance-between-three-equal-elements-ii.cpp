class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<vector<int>> mp(2,vector<int>(maxVal+1,-1));
        int mini=n+1;

        for(int i=0;i<n;i++)
        {
            int a=nums[i];

            if(mp[0][a]==-1)
                mp[0][a]=i;
            else if(mp[1][a]==-1)
                mp[1][a]=i;
            else{
                int curr=i-mp[0][a];
                mini=min(mini,curr);
                mp[0][a]=mp[1][a];
                mp[1][a]=i;
            }
        }

        if(mini==n+1) return -1;
        return mini*2;
    }
};