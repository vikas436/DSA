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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        vector<int>vec;
        bool flg = false;
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if(node==NULL) {
                if(flg) {
                    reverse(vec.begin(), vec.end());
                }
                res.push_back(vec);
                flg = !flg;
                vec.clear();
                if(que.empty()) return res;
                que.push(NULL);
                continue;
            }
            vec.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        return res;
    }
};
