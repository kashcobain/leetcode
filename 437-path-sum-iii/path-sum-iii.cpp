class Solution {
public:
    int count = 0;

    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (!root) return;

        // Step 1: Add current node
        path.push_back(root->val);

        // Step 2: Check all suffix sums
        long long sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == targetSum) count++;
        }

        // Step 3: Explore left and right
        dfs(root->left, targetSum, path);
        dfs(root->right, targetSum, path);

        // Step 4: Backtrack
        path.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return count;
    }
};
