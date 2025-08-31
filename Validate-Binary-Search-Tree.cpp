class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> p;
        inorder(root, p);

        for (int i = 1; i < p.size(); i++) {
            if (p[i] <= p[i-1]) return false; 
        }
        return true;
    }
};
