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
int dfs(TreeNode* root,int &ans)
{
    
   
   int left = (root->left ? dfs(root->left,ans) : 0);
    int right=(root->right?dfs(root->right,ans):0);
    ans+=abs(left-right);
    return left+right+root->val;

}
    int findTilt(TreeNode* root) {
        
        int ans=0;
      if(root)  {dfs(root,ans);}
        return ans;

        
    }
};