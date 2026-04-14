class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int arocks) {
        int n=capacity.size();
        vector<int> newm(n);
        for(int i=0;i<n;i++)
        {
            newm[i]=capacity[i]-rocks[i];

        }
        sort(newm.begin(),newm.end());

        int count=0;
        for(int i=0;i<n;i++)
        {
            if(newm[i]==0)count++;
            if(newm[i]>0)
            {
                if((arocks-newm[i])>=0)
                {
                    count++;
                    arocks=arocks-newm[i];
                }
            }
        }
return count;
    }
};