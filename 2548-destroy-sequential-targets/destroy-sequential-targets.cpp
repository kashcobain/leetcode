class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> freq;

        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] % space]++;
        }

        int maxi = 0;
        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++)
        {
            int rem = nums[i] % space;

            if(freq[rem] > maxi)
            {
                maxi = freq[rem];
                mini = nums[i];
            }
            else if(freq[rem] == maxi)
            {
                mini = min(mini, nums[i]);
            }
        }

        return mini;
    }
};