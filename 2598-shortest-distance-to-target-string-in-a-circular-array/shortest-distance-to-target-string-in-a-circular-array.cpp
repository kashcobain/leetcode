class Solution {
public:
    int closestTarget(vector<string>& words, string target, int st) {int n=words.size();
    if(find(words.begin(),words.end(),target)==words.end())
    {
        return -1;

    }
    int num2=0;
    int num1=0;
    for(int i=0;i<n;i++)
    {
        if(words[(st+i)%n]==target)
        {
            num1=i;
            break;

        }
    }
    for(int i=0;i<n;i++)
    {
        if(words[(st - i + n) % n]==target)
        {
            num2=i;
            break;

        }
    }

        if(num1>num2)
        {
            return num2;
        }
        else{
            return num1;
        }
    }
};