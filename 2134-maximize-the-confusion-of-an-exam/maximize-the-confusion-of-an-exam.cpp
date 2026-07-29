class Solution {
public:
    int answ(string key,int k,char a, char b)
    {
        int n=key.size();
        int cnt=0;
        int left=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(key[i]==b)
            {
                cnt++;
            }
            if(cnt>k)
            {
                if(key[left]==b){
                    cnt--;

                }
                left++;

            }
            if(cnt<=k)
            {
                ans=max(ans,i-left+1);

            }
        }
        return ans;

    }
    int maxConsecutiveAnswers(string answerKey, int k) {
         
         return max(answ(answerKey,k,'T','F'),answ(answerKey,k,'F','T'));
         
        
        
    }
};