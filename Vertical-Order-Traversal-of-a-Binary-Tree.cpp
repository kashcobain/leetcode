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
        if(root==nullptr)
        {
            return {};
        }
        unordered_map<int,vector<pair<int,int>>> mp;
        int mini=0;
        int maxi=0;
        int level=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto p=q.front();
                q.pop();
                TreeNode* k=p.first;
                int hd=p.second;
                if(k->left)
                {
                    mini=min(mini,hd-1);
                    q.push({k->left,hd-1});
                }
                if(k->right)
                {
                    maxi=max(maxi,hd+1);
                    q.push({k->right,hd+1});
                }
                mp[hd].push_back({level,k->val});

            }
            level++;
        }
        vector<vector<int>> ans;
        for(int i=mini;i<=maxi;i++)
        {
            sort(mp[i].begin(),mp[i].end());
            vector<int> temp;
            for(auto it:mp[i])
            {
                temp.push_back(it.second);
            }
            ans.push_back(temp);

        }
        return ans;
        
    }
};