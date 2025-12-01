class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        if(n>b.size()){
            return 0;
        }
        if(n==1){
            long long sum=0;
            sum=accumulate(b.begin(),b.end(),sum);
            return sum;
        }
        sort(b.begin(),b.end());
        long long e=0;
        
        for(int i=0;i<b.size()-n;i++){
            e+=b[i];
        }      
        
        long long ans=b[b.size()-n];
        vector<long long > c;
        
        for(int i=b.size()-n;i<b.size();i++){
            c.push_back(b[i]);
        }
        
        vector<long long> x(n);
        x[0]=c[1]-c[0];
        for(int i=1;i<c.size()-1;i++){
           
            x[i]=(i+1)*(c[i+1]-c[i]);
        }
        for(int i=0;i<x.size();i++) cout<<x[i]<<" ";
        for(int i=0;i<x.size()-1;i++){      
                     
                ans+=min(e/(i+1),((long long)x[i]/(i+1)));
                e-=x[i];
            if(e<=0){
                e=0;
                break;
            }
        }
        ans+=e/n;
        return ans;
    }
};