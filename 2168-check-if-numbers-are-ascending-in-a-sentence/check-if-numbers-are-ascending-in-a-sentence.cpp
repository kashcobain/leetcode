class Solution {
public:
    bool areNumbersAscending(string s) {

        int prev = INT_MIN;
        int curr = INT_MIN;

        stringstream ss(s);
        string word;

        vector<string> ans;

        while(ss >> word)
        {
            ans.push_back(word);
        }

        for(int i = 0; i < ans.size(); i++)
        {
            if(isdigit(ans[i][0]))
            {
                curr = stoi(ans[i]);

                if(curr <= prev)
                {
                    return false;
                }

                prev = curr;
            }
        }

        return true;
    }
};