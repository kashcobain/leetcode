class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[text[i]]++;
        }
        mp['l']=mp['l']/2;
        mp['o']=mp['o']/2;
        int mini=INT_MAX;

        return mini=min({mp['b'],mp['a'],mp['l'],mp['o'],mp['n']});
        
    }
};