class Solution {
public:
    bool ispal(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int ind,string s,vector<vector<string>> &ans,vector<string> &temp)
    {
        int n=s.size();
        if(ind==n)
        {
            ans.push_back(temp);
            return;
            
        }
        for(int k=ind;k<n;k++)
        {
            string base=s.substr(ind,-ind+k+1);
            if(ispal(base))
            {
                temp.push_back(base);
                solve(k+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,ans,temp);
        return ans;
        
    }
};