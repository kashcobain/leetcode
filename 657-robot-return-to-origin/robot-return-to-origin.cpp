class Solution {
public:
    bool judgeCircle(string moves) {
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='U')
            {
                a++;
            }
            else if(moves[i]=='D')
            {
                b++;
            }
            else if(moves[i]=='L')
            {
                c++;
            }
            else{
                d++;
            }
        }
        return (a==b && c==d);
    }
};