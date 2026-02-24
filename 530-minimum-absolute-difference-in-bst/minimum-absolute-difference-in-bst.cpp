class Solution {
public:
    void traverse(TreeNode* root, vector<int> &ans)
    {
        if(root==nullptr) return;
        traverse(root->left,ans);
        ans.push_back(root->val);
        traverse(root->right,ans);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> temp;
        traverse(root,temp);

        int mini = INT_MAX;

        for(int i=1;i<temp.size();i++)
        {
            mini = min(mini, temp[i] - temp[i-1]);
        }

        return mini;
    }
};