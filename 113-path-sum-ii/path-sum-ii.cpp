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
    void dfs(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& ans) {
        // Base case
        if (!root) return;

        // Step 1: Include current node
        path.push_back(root->val);

        // Step 2: Check if it’s a leaf and path sum matches target
        if (!root->left && !root->right && root->val == target) {
            ans.push_back(path);  // store a copy of the current path
        } 
        else {
            // Step 3: Explore left and right subtrees
            dfs(root->left, target - root->val, path, ans);
            dfs(root->right, target - root->val, path, ans);
        }

        // Step 4: Backtrack — remove current node before returning
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }
};
