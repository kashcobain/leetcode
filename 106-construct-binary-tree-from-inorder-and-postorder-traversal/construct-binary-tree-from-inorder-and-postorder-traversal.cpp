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
    TreeNode* builder(vector<int>& postorder,int poststart,int postend ,vector<int>& inorder,int instart,int inend,unordered_map<int,int> &mp)
    {
        if(poststart>postend)return nullptr;
        TreeNode* root=new TreeNode(postorder[postend]);
        int inroot=mp[root->val];
        int numsleft=inroot-instart;
        root->left=builder(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,mp);
        root->right=builder(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,mp);
    return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return builder(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};