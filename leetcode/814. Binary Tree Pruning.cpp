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
    int prune(TreeNode* root) {
        if(!root) return 0;
        int l = prune(root->left);
        int r = prune(root->right);
        if(l==0 && root->left) root->left = NULL;
        if(r==0 && root->right) root->right = NULL;
        return max(root->val, max(l, r));
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        prune(root);
        if(root->val==0 && !root->left && !root->right) return NULL;
        return root;
    }
};
