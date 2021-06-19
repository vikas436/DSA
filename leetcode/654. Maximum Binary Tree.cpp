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
    int valid(vector<int>&nums, int l, int r) {
        int m = l;
        for(int i=l;i<=r;i++) {
            if(nums[i]>nums[m]) m = i;
        }
        return m;
    }
    TreeNode* tree(vector<int>& nums, int l, int r) {
        int num = valid(nums, l, r);
        if(l>r) return NULL;
        TreeNode* root = new TreeNode(nums[num]);
        root->left = tree(nums, l, num-1);
        root->right = tree(nums, num+1, r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return tree(nums, 0, nums.size()-1);
    }
};
