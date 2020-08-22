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
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {
        res = 1;
        depth(root);
        return res - 1; 
    }
    int depth(TreeNode* root) {
        if(root==NULL) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        res = max(res , 1 + l + r);
        return 1 + max(l, r);
    }
};
