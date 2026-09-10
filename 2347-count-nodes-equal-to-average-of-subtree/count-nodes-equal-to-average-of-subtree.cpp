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
    pair<int ,int> solve(TreeNode* root,int &cnt)
    {
        if(root==NULL)return {0,0};
        if(!root->left && !root->right){
            cnt++;

            return {1,root->val};}
        auto lft=solve(root->left,cnt);
        auto rght=solve(root->right,cnt);
        int ndcnt=1+lft.first+rght.first;
        int val=root->val+lft.second+rght.second;
       if((int)(val/ndcnt) == root->val)cnt++;
        return {ndcnt,val};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        solve(root,cnt);
        return cnt;
        
    }
};