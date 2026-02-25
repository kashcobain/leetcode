class Solution {
public:
    void sum(TreeNode* root, vector<string> &ans, string &temp)
    {
        if(root == nullptr)
            return;

        temp += to_string(root->val);

        if(root->left == nullptr && root->right == nullptr) {
            ans.push_back(temp);
        }
        else {
            sum(root->left, ans, temp);
            sum(root->right, ans, temp);
        }

        temp.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        sum(root, ans, temp);

        int res = 0;
        for(int i = 0; i < ans.size(); i++) {
            res += stoi(ans[i]);
        }

        return res;
    }
};