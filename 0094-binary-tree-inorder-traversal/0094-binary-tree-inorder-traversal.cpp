/* class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};
*/ 

// TC is O(N) 

class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode* > s;

     vector<int> i;
     TreeNode* Node = root;


     while(true){
        if(Node != NULL){
            s.push(Node);
            Node = (Node -> left);
        }
        else{
            if(s.empty() == true) break;
            Node = s.top();
            s.pop();
            i.push_back(Node -> val);

            Node =  Node-> right;
        }

        
        
     }
return i;

    }
};