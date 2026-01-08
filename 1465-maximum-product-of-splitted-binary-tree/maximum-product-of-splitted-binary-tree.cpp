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
long long ans=0;
int mod=1e9+7;
long long total=0;


long long dfs(TreeNode* root)
{
    if(root==nullptr)return 0;
   return root->val+dfs(root->left)+dfs(root->right);
}
long long dfsprod(TreeNode* root)
{
    if(root==nullptr)return 0;
    long long left=dfsprod(root->left);
    long long right=dfsprod(root->right);
    long long sum=root->val+left+right;
    ans=max(ans,sum*(total-sum));
    return sum;
}

    int maxProduct(TreeNode* root) {
        total=dfs(root);
        dfsprod(root);
        return ans%mod;
        
    }
};