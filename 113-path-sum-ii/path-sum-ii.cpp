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
    void pathsum(TreeNode* root,vector<vector<int>> &ans,int target,vector<int> currpath)
    {
        if(root==nullptr)return ;
        currpath.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr)
        {
            if(root->val==target )
            {
                ans.push_back(currpath);
                return; 
            }
            return;
        }
       pathsum(root->left,ans,target-root->val,currpath);
       pathsum(root->right,ans,target-root->val,currpath);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        pathsum(root,ans,targetSum,{});
        return ans;
        
    }
};