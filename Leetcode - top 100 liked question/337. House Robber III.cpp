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
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int sum = 0;
        if(root->left) {
             if(root->left->left) {
                dp[root->left->left] = rob(root->left->left);
                sum += dp[root->left->left];
            }
            if(root->left->right) {
                dp[root->left->right] = rob(root->left->right);
                sum += dp[root->left->right];
            }
        }
        if(root->right) {
             if(root->right->left) {
                dp[root->right->left] = rob(root->right->left);
                sum += dp[root->right->left];
            }
            if(root->right->right) {
                dp[root->right->right] = rob(root->right->right);
                sum += dp[root->right->right];
            }
        }
        
        int mx = 0;
        if(root->left) {
            dp[root->left]=rob(root->left);
            mx+=dp[root->left];
        }
        if(root->right) {
            dp[root->right]=rob(root->right);
            mx+=dp[root->right];
        }
        return max(sum+root->val, mx);
    }
    
    int robRecursion(TreeNode* root) {
        if(root==NULL) return 0;
        int sum = 0;
        if(root->left!=NULL) sum+=rob(root->left->left)+rob(root->left->right);
        if(root->right!=NULL) sum+=rob(root->right->left)+rob(root->right->right);
        return max(sum+root->val, rob(root->left)+rob(root->right));
    }
};
