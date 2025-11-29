class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> sti;
        for(int i=0;i<s.size();i++)
        {
            sti.push(s[i]);
        }
        
        for(int i=0;i<s.size();i++)
        {
            s[i]=sti.top();
            sti.pop();
        }

    }
};