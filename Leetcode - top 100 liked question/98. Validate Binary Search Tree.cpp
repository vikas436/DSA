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
    bool isBST(TreeNode *root, int mn, int mx) {
        if(root==NULL) return true;
        // cout<<mn<<" "<<root->val<<" "<<mx<<endl;
        if(mn!=-1 && root->val <= mn) return false;
        if(mx!=-1 && root->val >= mx) return false;
        return isBST(root->left, mn, root->val) && isBST(root->right, root->val, mx);
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root, -1, -1);
    }
};
