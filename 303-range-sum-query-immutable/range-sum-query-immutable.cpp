class NumArray {
    vector<int> presum;
public:
    NumArray(vector<int>& nums) {
      presum.push_back(nums[0]);
      for(int i=0;i<nums.size();i++)
      {
        presum.push_back(presum.back()+nums[i]);
      }
        
    }
    
    int sumRange(int left, int right) {

        return presum[right+1]-presum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */