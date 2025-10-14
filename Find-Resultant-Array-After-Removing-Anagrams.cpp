class Solution {
public:
    bool isana(string a,string b)
    {
     
        int n=a.size();
        int m=b.size();
        if(n!=m)
        {
            return false;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b)return true;
        else{
            return false;
        }



    }
    vector<string> removeAnagrams(vector<string>& words) {
        int i = 0;
        while (i < words.size() - 1) {
            if (isana(words[i], words[i + 1])) {
                words.erase(words.begin() + i + 1);
            } else {
                i++;
            }
        }
        return words;
    }
};