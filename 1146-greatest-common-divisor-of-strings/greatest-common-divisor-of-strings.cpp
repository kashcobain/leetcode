class Solution {
public:
    bool issub(string s1, string s2, string check)
    {
        int n = check.size();

        if (n == 0) return false;

        if (s1.size() % n != 0 || s2.size() % n != 0)
            return false;

        for (int i = 0; i < s1.size(); i += n)
        {
            if (s1.substr(i, n) != check)
                return false;
        }

        for (int i = 0; i < s2.size(); i += n)
        {
            if (s2.substr(i, n) != check)
                return false;
        }

        return true;
    }

    string pre(string s1, int n)
    {
        return s1.substr(0, n);
    }

    string gcdOfStrings(string str1, string str2) {

        int n1 = str1.size();
        int n2 = str2.size();

        int small = min(n1, n2);
        string smals = (n1 > n2) ? str2 : str1;

        for (int i = small; i >= 1; i--)
        {
            string check = smals.substr(0, i);

            if (issub(str1, str2, check))
            {
                return check;
            }
        }

        return "";
    }
};