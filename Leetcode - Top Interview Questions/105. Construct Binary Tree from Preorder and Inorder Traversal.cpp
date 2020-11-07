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
    int getInd(vector<int>& inorder, int val) {
        for(int i=0;i<inorder.size();i++) {
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder,int &ind, int l, int r) {
        if(l>r) return NULL;
        int mid = getInd(inorder, preorder[ind++]);
        TreeNode* node = new TreeNode(inorder[mid]);
        node->left = tree(preorder, inorder, ind, l, mid-1);
        node->right = tree(preorder, inorder, ind, mid+1, r);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        int ind = 0;
        return tree(preorder, inorder, ind, 0, inorder.size()-1);
    }
};
