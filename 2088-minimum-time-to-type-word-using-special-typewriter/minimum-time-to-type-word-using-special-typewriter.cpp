class Solution {
public:
    int dis(char c1,char c2)
    {
        int a=c1-'a';
        int b=c2-'a';
        return min(abs(b-a), 26 - abs(b-a));
    }

    int minTimeToType(string word) {
        int n = word.size();
        int ans = 0;

        ans += dis('a', word[0]) + 1;

        for(int i = 1; i < n; i++)
        {
            ans += dis(word[i], word[i-1]) + 1;
        }

        return ans;
    }
};