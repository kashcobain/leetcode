class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
       
        int ans=0;
        int gcdval=0;
        for(auto num:nums)
        {
            
            if(num==1)
            {
                ans++;
            }
            gcdval=gcd(gcdval,num);
        }
        if(gcdval>1)return -1;
       
    if(ans>0)return n-ans;
   int min_len = n;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            if (g == 1) {
                min_len = 1;
                break; 
            }
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break;
                }
            }
        }

        return min_len + n - 2;
    }
};