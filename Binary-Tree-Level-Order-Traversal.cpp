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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
        int size = q.size();
        vector<int> value;
        
        for(int i = 0; i < size; i++){
            TreeNode* data = q.front();
            q.pop();
            if(data->left != NULL) q.push(data->left);
            if(data->right != NULL) q.push(data->right);
            value.push_back(data->val);
        }
            ans.push_back(value);
        }
        return ans;
    }
};