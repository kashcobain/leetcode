class Solution {
public:
    int zleft(string k)
    {
        int count = 0;
        for(int i = 0; i < k.size(); i++)
        {
            if(k[i] == '0')
            {
                count++;
            }
        }
        return count;
    }

    int zright(string k)
    {
        int count = 0;
        for(int i = 0; i < k.size(); i++)
        {
            if(k[i] == '1')
            {
                count++;
            }
        }
        return count;
    }

    int maxScore(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 1; i < n; i++)
        {
           
            string p = s.substr(0, i);
            string q = s.substr(i, n-i);

           
            ans = max(ans, zleft(p) + zright(q));
        }

        return ans;
    }
};
