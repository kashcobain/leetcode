class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res="";
        char prev1='#';
        char prev2='#';
        while(a>0 && b>0){
            if(a>b){
                if(prev1=='a' && prev2=='a'){
                    res+='b';
                    b--;
                    prev1=prev2;
                    prev2='b';
                }
                else{
                    res+='a';
                    a--;
                    prev1=prev2;
                    prev2='a';
                }
            }
            else{
                if(prev1=='b' && prev2=='b'){
                    res+='a';
                    a--;
                    prev1=prev2;
                    prev2='a';
                }
                else{
                    res+='b';
                    b--;
                    prev1=prev2;
                    prev2='b';
                }
            }
        }
        while(a>0){
            res+='a';
            a--;
        }
        while(b>0){
            res+='b';
            b--;
        }
        return res;
    }
};