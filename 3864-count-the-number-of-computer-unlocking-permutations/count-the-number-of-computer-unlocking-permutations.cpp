class Solution {
public:
int fact(int n)
{
    int mod=1e9+7;
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
       ans=(ans*i)%mod;

    }
    return ans;
}
    int countPermutations(vector<int>& complexity) {
        int mod=1e9+7;
        int count=0;
        int mini=*min_element(complexity.begin(),complexity.end());
        for(auto it:complexity)
        {
            if(it==mini)
            {
                count++;
            }
        }
        if(complexity[0]!=mini)return 0;
        int n=complexity.size()-1;
        if(count>=2)return 0;
        else
         return fact(n);



        
    }
};