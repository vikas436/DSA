
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *node1 = NULL;
    void getIfSamePath(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return;
        if(root==p) node1 = p;
        if(root==q) node1 = q;
        getIfSamePath(root->left, p, q);
        getIfSamePath(root->right, p, q); 
    }
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root==p) return p;
        if(root==q) return q;
        TreeNode *l = lca(root->left, p, q);
        TreeNode *r = lca(root->right, p, q);
        if(l != NULL && r != NULL) return root;
        if(l) return l;
        else return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        getIfSamePath(root, p, q);
        TreeNode *node2 = lca(root, p, q);
        if(node2) return node2;
        return node1;
    }
};
