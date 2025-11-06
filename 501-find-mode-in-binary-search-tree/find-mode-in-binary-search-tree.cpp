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
    void dfs(TreeNode* root,unordered_map<int,int>& mp)
    {
        if(root==nullptr)return;
        dfs(root->left,mp);
        mp[root->val]++;
        dfs(root->right,mp);

    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        dfs(root,mp);
        int maxfr=0;
        for(auto it:mp)
        {   
            maxfr=max(maxfr,it.second);

        }
        vector<int> ans;
        for(auto it:mp)
        {
            if(it.second==maxfr)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};