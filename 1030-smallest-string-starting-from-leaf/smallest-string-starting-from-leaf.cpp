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
string smalleststring;
    void solve(TreeNode* root,string curstring)
    {
        if(!root)return;
        curstring=char(root->val+'a')+curstring;
        if(!root->left && !root->right)
        {
            if(smalleststring==""||smalleststring>curstring)
            {
                smalleststring=curstring;
            }
        }
        if(root->left){
            solve(root->left,curstring);
        }
        if(root->right)solve(root->right,curstring);
    }
    string smallestFromLeaf(TreeNode* root) {
        
        solve(root,"");
        return smalleststring;

        
    }
};