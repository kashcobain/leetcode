class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> los;
        unordered_map<int,int> win;
        unordered_set<int> st;
        int n=matches.size();
        for(int i=0;i<n;i++)
        {
            win[matches[i][0]]++;
            los[matches[i][1]]++;
            st.insert(matches[i][0]);
            st.insert(matches[i][1]);

        }
        int number=st.size();
        vector<int> noloss={};
        vector<int> oneloss={};
        for(auto i:st)
        {
            if(los[i]==0)
            {
                noloss.push_back(i);
            }
           else if(los[i]==1)
            {
                oneloss.push_back(i);
            }
        }
        sort(noloss.begin(),noloss.end());
        sort(oneloss.begin(),oneloss.end());
        vector<vector<int>> ans;
          ans.push_back(noloss);
        ans.push_back(oneloss);
        
        return ans;
        

    }
};