class Solution {
public:
    bool func(string s1, string s2)
    {
        int n = s1.size();
        if(n != s2.size()) return false;

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(s1[i] != s2[i])
            {
                count++;
                if(count > 2) return false; 
            }
        }

        return true;  
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(int i = 0; i < queries.size(); i++)
        {
            for(int j = 0; j < dictionary.size(); j++)
            {
                if(func(queries[i], dictionary[j]))
                {
                    ans.push_back(queries[i]);
                    break;  
                }
            }
        }

        return ans;
    }
};