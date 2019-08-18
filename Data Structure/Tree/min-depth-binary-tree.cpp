// https://www.interviewbit.com/problems/min-depth-of-binary-tree/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(A==NULL) return INT_MAX;
    if(A->left==NULL && A->right==NULL) return 1;
    int l = minDepth(A->left);
    int r = minDepth(A->right);
    return 1+min(l,r);
}
