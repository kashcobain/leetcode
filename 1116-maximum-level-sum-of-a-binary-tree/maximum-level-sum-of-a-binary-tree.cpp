class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = INT_MIN;
        int level = 0;
        int strength = 0;

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            level++;

            while (size--) {
                TreeNode* k = q.front();
                q.pop();

                sum += k->val;

                if (k->left) q.push(k->left);
                if (k->right) q.push(k->right);
            }

            if (sum > ans) {
                ans = sum;
                strength = level;
            }
        }
        return strength;
    }
};
