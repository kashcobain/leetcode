class Solution {
public:
    vector<int> digits(int n)
    {
        vector<int> ans;
        while(n>0)
        {
            int digit=n%10;
            ans.push_back(digit);
            n=n/10;
        }
         reverse(ans.begin(),ans.end());
         return ans;
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            vector<int> k=digits(nums[i]);
            int l=k.size();
            for(int j=0;j<l;j++)
            {
                ans.push_back(k[j]);
            }
        }

        return ans;
    }
};