class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
       
    unordered_map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        sort(nums.begin(),nums.end());
        for(auto it:nums)
        {
            if(mp[it]>0)
           { for(int i=it+1;i<it+k;i++)
            {
                if(mp[i]==0)return false;
                mp[i]--;
            }
            mp[it]--;}
        }
        return true;
    }
};