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
    TreeNode* helper(vector<int>& preorder, int preLeft, int preRight,
                     vector<int>& inorder, int inLeft, int inRight,
                     unordered_map<int,int>& mp) 
    {
        if (preLeft > preRight) return nullptr;

        int rootVal = preorder[preLeft];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIdx = mp[rootVal];
        int leftSize = inRootIdx - inLeft;

        root->left = helper(preorder, preLeft + 1, preLeft + leftSize,
                            inorder, inLeft, inRootIdx - 1, mp);

        root->right = helper(preorder, preLeft + leftSize + 1, preRight,
                             inorder, inRootIdx + 1, inRight, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return helper(preorder, 0, preorder.size() - 1,
                      inorder, 0, inorder.size() - 1, mp);
    }
};
