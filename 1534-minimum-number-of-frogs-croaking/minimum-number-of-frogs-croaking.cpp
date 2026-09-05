class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        int frogs = 0, ans = 0;

        for(int i = 0; i < croakOfFrogs.size(); i++)
        {
            if(croakOfFrogs[i] == 'c')
            {
                c++;
                frogs++;
                ans = max(ans, frogs);
            }
            else if(croakOfFrogs[i] == 'r')
            {
                if(c == r)
                    return -1;

                r++;
            }
            else if(croakOfFrogs[i] == 'o')
            {
                if(r == o)
                    return -1;

                o++;
            }
            else if(croakOfFrogs[i] == 'a')
            {
                if(o == a)
                    return -1;

                a++;
            }
            else if(croakOfFrogs[i] == 'k')
            {
                if(a == k)
                    return -1;

                k++;
                frogs--;
            }
        }

        if(c != k)
            return -1;

        return ans;
    }
};