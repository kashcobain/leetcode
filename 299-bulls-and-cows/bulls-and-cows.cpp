class Solution {
public:
    string getHint(string secret, string guess) {
        vector <int> numsSecret(10,0); // digit counts for secret
        vector <int> numsGuess(10,0);  // digit counts for guess
        string answer="";
        string bull="";
        string cow="";
        int cowNums=0;
        int length=secret.size();
        int bullNums=0;

        // First pass: count bulls and digit frequencies
        for(int i=0;i<length;i++){
            if(secret[i]==guess[i])
                bullNums++; // direct match (bull)
            numsSecret[secret[i]-'0']++; // count digit in secret
            numsGuess[guess[i]-'0']++;   // count digit in guess
        }

        // Second pass: sum min counts for each digit
        for(int i=0;i<10;i++){
            cowNums+=min(numsSecret[i],numsGuess[i]);
        }
        cowNums-=bullNums; // remove bulls from overall matches to get true cows

        // Convert bulls count to string (handles multi-digit numbers)
        if(bullNums==0) bull='0'; // special case for zero bulls
        while(bullNums>0){
            bull=(char)(bullNums%10 + '0')+bull;
            bullNums/=10;
        }

        // Convert cows count to string
        if(cowNums==0) cow='0';
        while(cowNums>0){
            cow=(char)(cowNums%10 + '0')+cow;
            cowNums/=10;
        }

        answer+=bull;
        answer+='A';
        answer+=cow;
        answer+='B';
        return answer; 
    }
};