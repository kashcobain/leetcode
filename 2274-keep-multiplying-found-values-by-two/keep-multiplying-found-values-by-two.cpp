class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while(find(nums.begin(),nums.end(),original)!=nums.end())
        {
            original=original*2;
        }
return original;
}
};