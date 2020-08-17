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
    int getNum(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2 == NULL) return -1;
        if(t1==NULL && t2!=NULL) return t2->val;
        if(t1!=NULL && t2==NULL) return t1->val;
        return t1->val+t2->val;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2 == NULL) return NULL;
        if(t1==NULL && t2!=NULL) return t2;
        if(t1!=NULL && t2==NULL) return t1;
        int num = getNum(t1, t2);
        TreeNode *node = new TreeNode(num);
        node->left = mergeTrees(t1->left, t2->left); 
        node->right = mergeTrees(t1->right, t2->right); 
        return node;
    }
};
