class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int mid=0;
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            mid+=nums[i];

        }
        mid=mid/n;
       
        for(int i=max(mid+1,1);i<=max(maxi,1);i++)
        {
            if(mp.find(i)==mp.end())
            {
                return i;

            }
        }
        return maxi+1;

    }
};  