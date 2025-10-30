class Solution {
public:
    
    int maxfre(unordered_map<char,int> &mp) {
        int maxi = 0;
        for (auto it : mp) {
            if (it.second > maxi) {
                maxi = it.second;
            }
        }
        return maxi;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int maxi = 0;
        unordered_map<char,int> mp;

        for (int right = 0; right < n; right++) {
            mp[s[right]]++;

            int maxfreq = maxfre(mp);

            
            if (right - left + 1 - maxfreq <= k) {
                int ans = right - left + 1;
                maxi = max(ans, maxi);
            } 
            else {
                
                mp[s[left]]--;
                left++;
            }
        }

        return maxi;
    }
};
