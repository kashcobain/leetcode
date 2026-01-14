class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double high=INT_MIN;
        double low=INT_MAX;
        double ans=0.0;
        for(auto &s:squares)
        {
            double y=s[1];
            double len=s[2];
            ans+=len*len;
            if(y<low)low=y;
            if(y+len>high)high=y+len;
        }
        double half=ans/2.0;
        for(int i=0;i<100;i++)
        {
            double mid=(low+high)/2.0;
            double area_below=0;
            for(auto &sq:squares)
            {
                double y=sq[1];
                double l=sq[2];
                if(mid<=y)
                {
                    area_below+=0.0;
                }
                else if(mid>=y+l)
                {
                    area_below+=l*l;
                }
                else{
                    area_below+=(mid-y)*l;
                }
            }
            if(area_below<half)
            {
                low=mid;
            }
            else{
                high=mid;
            }

        }

        return high;
        
    }
};