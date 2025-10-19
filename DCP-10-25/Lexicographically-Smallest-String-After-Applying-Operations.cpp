class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n=s.size();
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        string ans=s;
        visited.insert(s);
        while(!q.empty())
        {
            string node=q.front();
            q.pop();
            if(node<ans)ans=node;
            string op1=node;
            for(int i=1;i<n;i+=2)
            {
                int digi=(op1[i]-'0'+a)%10;
                op1[i]=char(digi+'0');
            }
            if(visited.find(op1)==visited.end())
            {
                visited.insert(op1);
                q.push(op1);


            }
            string op2=node.substr(n-b)+node.substr(0,n-b);
            if(visited.find(op2)==visited.end())
            {
                visited.insert(op2);
                q.push(op2);
            }

        }
    return  ans;
    }
};