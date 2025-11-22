class Solution {
public:
vector<string> valid;
void generate(int n,int m,string &s)

{if(n==0 && m==0)
{
    valid.push_back(s);
    return;
}
     if(n>0)
{
   string s2=s;
    
        s2.push_back('(');
     
    
    generate(n-1,m,s2);
    
}
if(m>0 && m>n )
{
    string s1=s;
    s1.push_back(')');
    generate(n,m-1,s1);

}
}
    vector<string> generateParenthesis(int n) {
        string s;
        generate(n,n,s);
        return valid;
        
        
    }
};