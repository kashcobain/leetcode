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

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(!root) return {};

        
        unordered_map<int, unordered_map<int, vector<int>>> mp;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}});

        int minCol = 0;
        int maxCol = 0;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;

            int col = it.second.first;
            int row = it.second.second;

            mp[col][row].push_back(node->val);

            minCol = min(minCol, col);
            maxCol = max(maxCol, col);

            if(node->left)
            {
                q.push({
                    node->left,
                    {col - 1, row + 1}
                });
            }

            if(node->right)
            {
                q.push({
                    node->right,
                    {col + 1, row + 1}
                });
            }
        }

        vector<vector<int>> ans;

        for(int col = minCol; col <= maxCol; col++)
        {
            vector<int> temp;

          
            for(int row = 0; row <= 1000; row++)
            {
                if(mp[col].count(row))
                {
                   
                    sort(mp[col][row].begin(), mp[col][row].end());

                    for(auto val : mp[col][row])
                    {
                        temp.push_back(val);
                    }
                }
            }

            if(!temp.empty())
                ans.push_back(temp);
        }

        return ans;
    }
};