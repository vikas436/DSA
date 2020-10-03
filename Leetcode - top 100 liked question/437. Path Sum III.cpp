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
    int res;
    void pathSum(TreeNode* root, int sum, int cnt) {
        if(root==NULL) return;
        if(cnt+root->val==sum) res++;
        pathSum(root->left, sum, cnt+root->val);
        pathSum(root->right, sum, cnt+root->val);
    }
    void pathRec(TreeNode* root, int sum) {
         if(root==NULL) return;
        int cnt=0;
        pathSum(root, sum, cnt);
        pathRec(root->left, sum);
        pathRec(root->right, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        res = 0; 
        pathRec(root, sum);
        return res;
    }
};
