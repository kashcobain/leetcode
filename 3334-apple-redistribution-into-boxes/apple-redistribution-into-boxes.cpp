class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(auto it:apple)
        {
            sum+=it;
        }
        sort(capacity.begin(),capacity.end());
        int ans=0;
        int newi=0;
        for(int i=capacity.size()-1;i>=0;i--)
        {
            ans++;
             newi +=capacity[i];
            if(newi>=sum)
            {
                return ans;
            }
        }

        return -1;
    }
};