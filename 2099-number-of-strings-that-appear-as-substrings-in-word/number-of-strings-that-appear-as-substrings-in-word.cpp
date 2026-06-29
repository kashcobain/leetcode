class Solution {
public:
    bool contains(string &s1,string &s2)
    {
        int n=s1.size();
        int m=s2.size();
        for(int i=0;i<m-n+1;i++)
        {
            if(s2.substr(i,n)==s1)
            {
                return true;
            }

        }
    return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(contains(patterns[i],word))
            {
                count++;
            }



        }
        return count;
    }
};