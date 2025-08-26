class Solution {
public:
    int dfs(TreeNode* root, int &maxi)
    {
        if(root==nullptr)  // agar node hi nahi hai
        {
            return 0;  // height = 0
        }

        int lh=dfs(root->left,maxi);   // left subtree ki height
        int rh=dfs(root->right,maxi);  // right subtree ki height

        maxi=max(maxi,lh+rh);          // yahan diameter update kar rahe hain

        return max(lh,rh)+1;           // current node ki height return karo
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;  // initially diameter = 0
        dfs(root,maxi);  // dfs chalaya, reference se maxi update hota raha
        return maxi;     // sabse bada diameter return
    }
};
