class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        vector<int> v;
        unordered_map<char,int> mp;
        int cows=0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
            }
            else{
                mp[secret[i]]++;
                v.push_back(i);
            }
        }
        for(int i:v)
        {
            if(mp[guess[i]])
            {
                mp[guess[i]]--;
                cows++;
            }
        }

        return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};