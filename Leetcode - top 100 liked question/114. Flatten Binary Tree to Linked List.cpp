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
    void link(TreeNode* l, TreeNode* r) {
        if(l==NULL) return;
        TreeNode* templ = l;
        TreeNode* tempr = r->right;
        l->left=NULL;
        while(l->right!=NULL) {
            l=l->right;
        }
        r->right=templ;
        l->right=tempr;
        r->left=NULL;
    }

    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->left);
        link(root->left, root);
        flatten(root->right);
    }
};
