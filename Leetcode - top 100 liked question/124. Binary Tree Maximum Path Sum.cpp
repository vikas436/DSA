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
    
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        helper(root, res);
        return res;
    }
        
    int helper(TreeNode* root, int &res)
    {
        if(root==NULL) return 0;
        int sumleft=helper(root->left, res);
        int sumright=helper(root->right, res);
        int cur=0, val=0;
        cur = max(max(sumleft+root->val, sumright+root->val), root->val);
        val = cur;
        cur = max(cur, sumleft+root->val+sumright);
        res = max(res, cur);
        return val;
    } 
};
