class Solution {
public:

    int solve(TreeNode* root,int &val)
    {
        if(root==nullptr) return 0;

        int l = solve(root->left,val);
        int r = solve(root->right,val);

        int temp = 1 + max(l,r);      
        int ans  = l + r;             

        val = max(val, ans);

        return temp;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int val = 0;
        solve(root,val);
        return val;
    }
};
