class Solution {
public:

    void dep(TreeNode* root, TreeNode* parent, int x, int depth,
             TreeNode* &foundparent, int &founddepth)
    {
        if(root == nullptr) return;

        if(root->val == x)
        {
            foundparent = parent;
            founddepth = depth;
            return;
        }

        dep(root->left, root, x, depth + 1, foundparent, founddepth);
        dep(root->right, root, x, depth + 1, foundparent, founddepth);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* p1 = nullptr;
        TreeNode* p2 = nullptr;
        int d1 = 0, d2 = 0;

        dep(root, nullptr, x, 0, p1, d1);
        dep(root, nullptr, y, 0, p2, d2);

        return (d1 == d2 && p1 != p2);
    }
};