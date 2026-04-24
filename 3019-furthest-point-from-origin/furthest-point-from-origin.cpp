class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int a=0;
        int b=0;

        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
            {
                a++;
            }
            else if(moves[i]=='R')
            {
                b++;
            }
        }
        if(a>b)
        {
            return moves.size()-2*b;
        }
        else if(a==b)
        {
            return moves.size()-a-b;
        }
        else{
            return moves.size()-2*a;
        }
    }
};