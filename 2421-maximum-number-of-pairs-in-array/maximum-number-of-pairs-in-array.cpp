class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int uc=0;
        int pc=0;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;

        }
        for(auto it:mp)
        {
            int k=it.second;
            uc+=k%2;
            pc+=k/2;

        }
        return {pc,uc};

        
    }
};