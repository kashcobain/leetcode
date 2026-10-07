class Solution {
public:

    void solve(int i, string &s, int k, string &temp,
               set<string> &ans, int diff)
    {
        if(i == s.size())
        {
            if(diff == 0)
            {
                if(temp.size() == k)
                {
                    ans.insert(temp);
                }
            }

            return;
        }


       

        if(s[i] == '(')
        {
            temp += s[i];
            diff++;

            solve(i+1, s, k, temp, ans, diff);

            temp.pop_back();
            diff--;
        }
        else if(s[i] == ')')
        {
            if(diff > 0)
            {
                temp += s[i];
                diff--;

                solve(i+1, s, k, temp, ans, diff);

                temp.pop_back();
                diff++;
            }
        }
        else
        {
            temp += s[i];

            solve(i+1, s, k, temp, ans, diff);

            temp.pop_back();
        }


        

        solve(i+1, s, k, temp, ans, diff);
    }


    vector<string> removeInvalidParentheses(string s)
    {
        int remove = 0;
        int diff = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                diff++;
            }
            else if(s[i] == ')')
            {
                if(diff > 0)
                    diff--;
                else
                    remove++;
            }
        }

        remove += diff;

        int k = s.size() - remove;

        string temp = "";
        set<string> ans;

        solve(0, s, k, temp, ans, 0);

        vector<string> result;

        for(auto x : ans)
        {
            result.push_back(x);
        }

        return result;
    }
};