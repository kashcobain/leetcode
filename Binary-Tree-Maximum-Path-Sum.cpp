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
int dfs(TreeNode* root,int &maxi)
{
    if(root==nullptr)
    {
        return 0;
    }
    int lefti=max(0,dfs(root->left,maxi));
    int righti=max(0,dfs(root->right,maxi));
    int currsum=root->val+lefti+righti;
    maxi=max(maxi,currsum);
    return root->val+max(lefti,righti);


}
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        dfs(root,maxi);
        return maxi;
        
    }
};