class Solution {
public:
    bool isvow(char c)
    {
        if(c=='a'|| c=='e'|| c=='i'||c=='o'||c=='u')
        {
            return true;
        }
        return false;
    }
    int countVowelSubstrings(string word) {
       int cnt=0;
       for(int i=0;i<word.size();i++)
       {
        unordered_set<char> st;
        for(int j=i;j<word.size();j++)
        {
            if(!isvow(word[j]))break;
            st.insert(word[j]);
            if(st.size()==5)cnt++;
            

        }
       }
       return cnt;
    }
};