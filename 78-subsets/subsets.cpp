class Solution {
public:
void ans(vector<int> nums,vector<int> op,vector<vector<int>> &answ)
{
    if(nums.size()==0)
    {
        answ.push_back(op);
    return;

    }
    vector<int> op1=op;
    vector<int> op2=op;
    op2.push_back(nums[0]);
    nums.erase(nums.begin());
    ans(nums,op1,answ);
    ans(nums,op2,answ);


}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answ;
        vector<int> op;
        ans(nums,op,answ);
        return answ;

        
    }
};