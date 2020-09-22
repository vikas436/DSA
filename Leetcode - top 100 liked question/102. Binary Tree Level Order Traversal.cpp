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
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*>que;
        que.push(root);
        que.push(NULL);
        vector<int>vec;
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if(node==NULL) {
                res.push_back(vec);
                vec.clear();
                if(que.empty()) break;
                que.push(NULL);
            } else {
                vec.push_back(node->val);
                if(node->left != NULL) que.push(node->left);
                if(node->right != NULL) que.push(node->right);
            }
        }
        return res;
    }
};
