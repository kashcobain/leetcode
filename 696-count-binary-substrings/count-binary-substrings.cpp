class Solution {
public:
//isme ise groups me todha hai taaki groups ko ek maan le fir jo groups ka min size hai use hum use krke answer nikal lei ye greedy approach hai isse
    int countBinarySubstrings(string s) {
        int n=s.size();
        int prev=0,cur=1,ans=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                cur++;
            }
            else{
                ans+=min(cur,prev);
                prev=cur;
                cur=1;
            }
        }
        ans+=min(cur,prev);
        return ans;
        //ye l;ast wala hai taki bache huye ko hum add kr ske isme
        
    }
};