class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            
            vector<int> freq(26, 0);  
            
            for(int j = i; j < n; j++) {
                
                int c = s[j] - 'a';
                freq[c]++;
                
                int same = 0;
                bool flag = true;
                
                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        if(same == 0)
                            same = freq[k];
                        else if(freq[k] != same) {
                            flag = false;
                            break;
                        }
                    }
                }
                
                if(flag) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        return ans;  
    }
};
