class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int> ans;
        bool od=true;
        int minodd=1e9+7;
        int mineven=INT_MAX;
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]%2==0 && nums1[i]<mineven)
            {
                mineven=nums1[i];
            }
        
            if(nums1[i]%2!=0 && nums1[i]<minodd)
            {
                minodd=nums1[i];
            }
        }
        if(nums1[0]%2==0)
        {
            od=false;
        }
        else{
            od=true;
        }
        int mini=*min_element(nums1.begin(),nums1.end());
        if(od && mineven-minodd>=1)return true;
        else if(!od && minodd==1e9+7)return true;
        else return false;

        
        
    }
};