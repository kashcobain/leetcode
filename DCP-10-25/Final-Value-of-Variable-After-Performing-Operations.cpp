class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            string p=operations[i];
            if(p[0]=='+' || p[2]=='+')
            {
                count++;
            }
            else{
                count--;
            }
        }
        return count;
    }
};