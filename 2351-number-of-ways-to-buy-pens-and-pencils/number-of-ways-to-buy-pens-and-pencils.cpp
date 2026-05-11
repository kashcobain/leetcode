class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int maxpens=total/cost1;
        long long ans=0; 
        int base=total;
        for(int i=0;i<=maxpens;i++)
        {
            
            ans+=1+base/cost2;
            base=base-cost1;
            
            
            

        }
        return ans;
        
    }
};