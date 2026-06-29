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
    TreeNode* cons(vector<int> &ans,int i)
    { int n=ans.size();
        if(i>=n)return nullptr;

        TreeNode* newr=new TreeNode(ans[i]);
        
        newr->right=cons(ans,i+1);
        return newr;
    }
    void dfs(TreeNode* root,vector<int> &ans)
    {
        if(root==nullptr)return;
        ans.push_back(root->val);
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        sort(ans.begin(),ans.end());
        TreeNode* newr=cons(ans,0);
        return newr;
    }
};