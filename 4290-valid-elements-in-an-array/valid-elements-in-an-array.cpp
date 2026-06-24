class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            bool flagleft=true;
            for(int j=0;j<i;j++)
            {
                if(nums[i]<=nums[j])
                {
                    flagleft=false;
                    break;

                }
            }
            bool flagright=true;
            if(!flagleft)
          {  for(int j=i+1;j<n;j++)
            {
                if(nums[i]<=nums[j])
                {
                    flagright=false;
                    break;

                }
            }}
            if(flagleft ||flagright)
            {
                ans.push_back(nums[i]);
            }

        }
        return ans;
    }
};