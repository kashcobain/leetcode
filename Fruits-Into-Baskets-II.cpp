class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        for (int i=0;i<fruits.size();i++){
            for (int j=0;j<baskets.size();j++){
                if (fruits[i]<=baskets[j]){baskets[j]=0;break;}
            }
        }
        int ans=0;
        for (int i=0;i<baskets.size();i++){if (baskets[i]!=0){ans++;}}
        return ans;
    }
};