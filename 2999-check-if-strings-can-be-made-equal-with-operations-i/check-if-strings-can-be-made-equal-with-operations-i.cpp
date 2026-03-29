class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2)return true;
        string k=s1;


        for(int i=0;i<2;i++)
        {
            swap(s1[i],s1[i+2]);
            if(s1==s2)return true;
        }
    swap(k[1],k[3]);
    if(k==s2)return true;
    return false;
    
        
    }
};