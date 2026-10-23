class Solution {
public:
    void solve(TreeNode* root, int level, vector<vector<int>>& res) {
        if (root == nullptr) return;

        if (res.size() <= level)
            res.push_back({});

        res[level].push_back(root->val);

        solve(root->left, level + 1, res);
        solve(root->right, level + 1, res);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        solve(root, 0, res);
        return res;
    }
};