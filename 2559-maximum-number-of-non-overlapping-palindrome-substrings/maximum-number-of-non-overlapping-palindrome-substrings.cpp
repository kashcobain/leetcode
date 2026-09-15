class Solution {
public:
    int maxPalindromes(string s, int k) {
        
        int n=s.size();
        int lastend=0;
        int cnt=0;

        for(int center=0;center<2*n;center++)
        {
            int left=center/2;
            int right=left+center%2;

            while(left>=0 && right<n && s[left]==s[right])
            {
                if(right-left+1>=k)
                {
                    int end=right+1;

                    if(left>=lastend)
                    {
                        cnt++;
                        lastend=end;
                    }
                    else
                    {
                        lastend=min(lastend,end);
                    }

                    break;
                }

                left--;
                right++;
            }
        }

        return cnt;
    }
};