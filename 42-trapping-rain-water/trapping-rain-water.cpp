class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> lef(n);
        vector<int> rig(n);
        int ans=0;
        lef[0]=height[0];
        for(int i=1;i<n;i++)
        {
            lef[i]=max(lef[i-1],height[i]);
        }
        rig[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rig[i]=max(rig[i+1],height[i]);
        }
        for(int i=0;i<n;i++)
        {
            ans+=min(lef[i],rig[i])-height[i];
        }

        return ans;
    }
};