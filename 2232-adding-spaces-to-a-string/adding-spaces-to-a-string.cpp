class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res="";
        int j=0;
        for(int i=0;i<spaces.size();i++)
        {
            int cut=spaces[i];
            res+=s.substr(j,cut-j);
        res+=" ";
        j=cut;
        }
        return res+=s.substr(j);
    }
};