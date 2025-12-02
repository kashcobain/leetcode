class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1000000007LL;

        int n = points.size();
        unordered_map<int, long long> mp; 
        for (int i = 0; i < n; i++) {
            int y = points[i][1];
            mp[y]++;
        }

        long long sum = 0;      
        long long sumSq = 0;    

        for (auto &it : mp) {
            long long c = it.second;
            if (c >= 2) {
                
                long long bases = c * (c - 1) / 2;  
                bases %= MOD;

                sum = (sum + bases) % MOD;
                sumSq = (sumSq + (bases * bases) % MOD) % MOD;
            }
        }

        
        if (sum == 0) return 0;

        long long total = ( (sum * sum) % MOD - sumSq + MOD ) % MOD;

       
        long long inv2 = 500000004LL; 
        long long ans = (total * inv2) % MOD;

        return (int)ans;
    }
};
