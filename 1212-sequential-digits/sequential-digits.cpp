class Solution {
public:
    int base(int n)
    {
        string s = "";
        for(int i = 1; i <= n; i++)
        {
            s += (i + '0');
        }
        return stoi(s);
    }

    vector<int> ans(int n)
    {
        vector<int> res;

        string p = "";
        for(int i = 0; i < n; i++)
        {
            p += '1';
        }

        int k = stoi(p);
        int baseval = base(n);

        // n digits ke liye sirf (10-n) sequential numbers hote hain
        for(int i = 0; i < 10 - n; i++)
        {
            res.push_back(baseval);
            baseval += k;
        }

        return res;
    }

    int finds(int n)
    {
        return to_string(n).size();
    }

    vector<int> sequentialDigits(int low, int high)
    {
        int minsize = finds(low);
        int maxsize = finds(high);

        vector<int> res;

        for(int i = minsize; i <= maxsize; i++)
        {
            vector<int> allval = ans(i);

            for(int j = 0; j < allval.size(); j++)
            {
                if(allval[j] >= low && allval[j] <= high)
                {
                    res.push_back(allval[j]);
                }
            }
        }

        return res;
    }
};