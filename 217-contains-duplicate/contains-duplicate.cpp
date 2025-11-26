class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
            {
                return true;;
            }
        }
        return false;
    }
};
// // Contains Duplicate
//   class Solution {
//   public:
//       bool containsDuplicate(vector<int>& nums) {
//           unordered_map<int,int> mp;
//           for(auto i : nums) mp[i]++;
//           bool flag = false;
//           for(auto i : mp){
//               if(i.second >= 2) return true;
//           }
//           return flag;
//       }
//   };
//   // Contains Duplicate
//   class Solution {
//   public:
//       bool containsDuplicate(vector<int>& nums) {
//           map<int,int> mp;
//           for(auto i : nums) mp[i]++;
//           bool flag = false;
//           for(auto i : mp){
//               if(i.second >= 2) return true;
//           }
//           return flag;
//       }
//   };
//   // Set Approach
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         return nums.size() > set<int>(nums.begin(),nums.end()).size();
//     }
// };
// // Shorted Approach
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         bool flag = false;
//         for(int i =0;i<nums.size()-1;i++){
//             if(nums[i] == nums[i+1]) return true;
//         }
//         return flag;
//     }
// };