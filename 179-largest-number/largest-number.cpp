class Solution {
public:
   struct cmp{
    bool operator() (const string &a,const string &b)const
    {
        return a+b>b+a;
    }
   };
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(auto it:nums)
        {
            ans.push_back(to_string(it));

        }
        sort(ans.begin(),ans.end(),cmp());
        string res="";
        if(ans[0]=="0")return "0";
        for(int i=0;i<ans.size();i++)
        {
            res+=ans[i];

        }
        return res;
    }
};