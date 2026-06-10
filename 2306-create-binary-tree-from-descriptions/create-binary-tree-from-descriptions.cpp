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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> nodes;
        unordered_set<int> chl;
        for(auto it:descriptions)
        {
            int parent=it[0];
            int child=it[1];
            int isleft=it[2];
            if(!nodes.count(parent))
            {
                nodes[parent]=new TreeNode(parent);
            }
            if(!nodes.count(child))
            {
                nodes[child]=new TreeNode(child);
            }
            if(isleft)
            {
                nodes[parent]->left=nodes[child];

            }
            else{
                nodes[parent]->right=nodes[child];

            }
            chl.insert(child);
        }
        for(auto it:descriptions)
        {
            if(chl.find(it[0])==chl.end())
            {
                return nodes[it[0]];
            }
        }
        return nullptr;
    }
};