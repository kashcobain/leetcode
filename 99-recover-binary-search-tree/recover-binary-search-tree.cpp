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
    TreeNode* findnode(TreeNode* root, int val)
    {
        if (!root) return nullptr;
        if (root->val == val) return root;
        TreeNode* left = findnode(root->left, val);
        if (left) return left;
        return findnode(root->right, val);
    }

    void inorder(TreeNode* root, std::vector<int> &ans)
    {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    void recoverTree(TreeNode* root)
    {
        if (!root) return;
        std::vector<int> seq;
        inorder(root, seq);

        std::vector<int> bad;
        for (int i = 1; i < (int)seq.size(); i++) {
            if (seq[i] < seq[i - 1]) {
                if (bad.empty()) bad.push_back(seq[i - 1]);
                bad.push_back(seq[i]);
            }
        }

        if (bad.empty()) return;

        TreeNode* n1 = findnode(root, bad.front());
        TreeNode* n2 = findnode(root, bad.back());
        std::swap(n1->val, n2->val);
    }
};
