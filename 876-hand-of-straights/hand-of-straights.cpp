class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int k=groupSize;
        int n=hand.size();
        if(n%k!=0)return false;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[hand[i]]++;
        }
        sort(hand.begin(),hand.end());
        for(auto it:hand)
        {
            if(mp[it]>0)
            {
                for(int i=it+1;i<it+k;i++)
                {
                    if(mp[i]==0)return false;
                    mp[i]--;
                }
                mp[it]--;
            }
        }
        return true;
    }
};