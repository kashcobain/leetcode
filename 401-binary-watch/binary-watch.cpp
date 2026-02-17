class Solution {
public:
int cntsetbits(int num)
{
    return __builtin_popcount(num);
}
string formattime(int h,int m)
{
    string formattime=to_string(h)+":";
    if(m<10)
    {
        formattime+="0";
    }
    formattime+=to_string(m);
    return formattime;
}
    vector<string> readBinaryWatch(int turnedOn) {
vector<string> time;
for(int h=0;h<=11;h++)
{
    for(int m=0;m<=59;m++)
    {
        if(cntsetbits(h)+cntsetbits(m)==turnedOn)
        {
            time.push_back(formattime(h,m));
        }
    }
}
return time;
    }
};