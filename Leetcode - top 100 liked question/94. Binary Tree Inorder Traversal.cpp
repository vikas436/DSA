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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> stk;
        while(true) {
            if(root!=NULL) {                
                stk.push(root);
                root = root->left;
            } else {
                if(stk.empty()) break;
                root = stk.top();
                stk.pop();
                res.push_back(root->val);
                root=root->right;
            }
        }
        return res;
    }
};
