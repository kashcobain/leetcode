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
TreeNode* helper(vector<int>& preorder,int prestart,int preend,  vector<int>& postorder,int poststart,int postend,unordered_map<int,int> &mp)
{
    if(prestart>preend)return NULL;
    TreeNode* root=new TreeNode(preorder[prestart]);
    if(preend==prestart)return root;
    int leftroot=preorder[prestart+1];
    int idx=mp[leftroot];
    int leftsize=idx-poststart+1;

    root->left=helper(preorder,prestart+1,prestart+leftsize,postorder,poststart,idx,mp);
    root->right=helper(preorder,prestart+leftsize+1,preend,postorder,idx+1,postend-1,mp);
    return root;


}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<postorder.size();i++)
        {
            mp[postorder[i]]=i;
        }
        return helper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,mp);
        
    }
};