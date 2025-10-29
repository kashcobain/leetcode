class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k=p.size();
        int i=0;
        unordered_map<char,int> mpp;
        unordered_map<char,int> mps;
        for(auto c:p)
        {
            mpp[c]++;
        }
        vector<int> ans;
        int j=0;
while(j<s.size())
{
    mps[s[j]]++;
 
    if(j-i+1==k)
    {
        if(mps==mpp)
        {
            ans.push_back(i);
        }
         mps[s[i]]--;
         if (mps[s[i]] == 0) mps.erase(s[i]);
    i++;
    }
      j++;

}
        return ans;
    }
};