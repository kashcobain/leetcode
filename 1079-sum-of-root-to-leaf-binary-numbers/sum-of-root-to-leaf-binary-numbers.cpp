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
    void dfs(TreeNode* root,vector<string> &bin,string temp)
    {
        temp+=to_string(root->val);
        if(root->left)dfs(root->left,bin,temp);
        if(root->right)dfs(root->right,bin,temp);
        if(root->left==nullptr && root->right==nullptr)bin.push_back(temp);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string> bin;
        dfs(root,bin,"");
        int ans=0;
        for(int i=0;i<bin.size();i++)
        {
            string base=bin[i];
            int val=stoi(base,nullptr,2);
            ans+=val;

        }
return ans;
        
        
    }
};