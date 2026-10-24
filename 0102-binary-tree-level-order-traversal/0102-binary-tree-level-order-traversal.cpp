class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; i++) {
                TreeNode* Node = q.front();

                q.pop();

                if(Node->left != NULL) q.push(Node -> left);
                if(Node -> right != NULL) q.push(Node -> right);

                level.push_back(Node -> val);

            }
            ans.push_back(level);
        }
        return ans;
    }
};