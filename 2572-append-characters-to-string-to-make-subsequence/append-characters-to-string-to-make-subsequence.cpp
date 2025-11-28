class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size();
        int k=t.size();
        int i=0;
        int j=0;
     int   count=0;
        while(i<n && j<k)
        {
            if(s[i]==t[j])
            {
                count++;
                i++;
                j++;
            }
            else{
                i++;
            }

        }
        int ans=k-count;
        if(ans<0)
        {
            return 0;
        }
        else{
            return ans;
        }
    }
};