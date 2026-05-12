class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a,const vector<int>& b)const
        {
            if(a[1]-a[0]==b[1]-b[0])
            {
                return a<b;
            }
            return a[1]-a[0]>b[1]-b[0];

        }

    };
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        sort(tasks.begin(),tasks.end(),cmp());
        int ans=0;
        int curr=0;
        for(auto &task:tasks)
        {
            int actual=task[0];
            int mini=task[1];
            if(curr<mini)
            {
                ans+=mini-curr;
                curr=mini;
            }
            curr-=actual;
        }



        return ans;
    }
};