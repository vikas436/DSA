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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        vector<int>vec;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        vec.push_back(root->val);
        vector<int>res;
        while(!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if(node == NULL) {
                if(vec.size()>0) res = vec;
                if(que.empty()) break;
                que.push(NULL);
                vec.clear();
            } else {
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        int sum=0;
        for(int i=0;i<res.size();i++) sum+=res[i];
        return sum;
    }
};
