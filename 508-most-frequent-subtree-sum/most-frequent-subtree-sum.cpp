/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
unordered_map<int,int> mp;
int dfs(TreeNode* root)
{
    if(root==nullptr)return 0;
    int sum=dfs(root->left)+dfs(root->right)+root->val;
    mp[sum]++;
    return sum;

}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        dfs(root);
        int maxi=0;
        for(auto it:mp)
        {
            maxi=max(maxi,it.second);
        }
        for(auto it:mp)
        {
            if(it.second==maxi)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};