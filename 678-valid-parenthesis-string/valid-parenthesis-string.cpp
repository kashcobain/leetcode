class Solution {
public:
    bool checkValidString(string s) {
stack<int> starindex;
stack<int> stackindex;
for(int i=0;i<s.length();i++)
{
    if(s[i]=='(')
    {
        stackindex.push(i);
    }
    else if(s[i]=='*')
    {
        starindex.push(i);
    }
    else if(s[i]==')')
    {
        if(stackindex.empty() && starindex.empty())
        {
            return false;
        }
        else if(!stackindex.empty())
        {
            stackindex.pop();
        }
        else{
            starindex.pop();
        }
    }
}        
while(!stackindex.empty())
{
    if(starindex.empty()) return false;
    if(stackindex.top()>starindex.top())return false;
    stackindex.pop();
    starindex.pop();
}
return true;
    }
};