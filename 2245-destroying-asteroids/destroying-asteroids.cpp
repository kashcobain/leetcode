class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();

        sort(asteroids.begin(),asteroids.end());
        if(mass<asteroids[0])
        {
            return false;
        }
        vector<long long> presum(n+1,0);

        for(int i=0;i<n;i++)
        {
            presum[i+1]=presum[i]+asteroids[i];
        }
        for(int i=1;i<n;i++)
        {
            if(presum[i]+mass<asteroids[i])
            {
                return false;
            }
        }

        return true;
    }
};