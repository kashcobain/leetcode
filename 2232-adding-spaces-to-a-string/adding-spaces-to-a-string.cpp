class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int j = 0; // last cut position in s

        for (int i = 0; i < spaces.size(); i++) {
            int cut = spaces[i];            // yahan space lagana hai

            // j se leke cut-1 tak ka substring uthao
            res += s.substr(j, cut - j);

            // yahan space add karo
            res += " ";

            // ab next substring yahin se start hoga
            j = cut;
        }

        // last bacha hua part bhi add karna zaruri hai
        res += s.substr(j);

        return res;
    }
};
